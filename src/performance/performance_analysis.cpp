#include <iostream>

#ifdef WIN32
#include <time.h>
#endif

#include "performance_analysis.h"

CPerformanceAnalysis::CPerformanceAnalysis():
m_File("_performanceanalysis.log")
{

}

CPerformanceAnalysis::~CPerformanceAnalysis()
{
    Report_Analysis();
}

int CPerformanceAnalysis::AddFunction(std::string _Name)
{
    m_Functions[_Name].AccesTime++;
    m_CurrentFunction = _Name;

    return 1;
}

void CPerformanceAnalysis::GetCurrentTime(int& _hour, int& _minute, int& _second)
{
#ifdef WIN32
    time_t timer1;
    time(&timer1);
    struct tm *Time1;
    Time1 = localtime(&timer1);
    _hour = Time1->tm_hour;
    _minute = Time1->tm_min;
    _second = Time1->tm_sec;
#endif
}

void CPerformanceAnalysis::GetPreciseCurrentTime(int& _millisecond)
{
#ifdef WIN32
    _millisecond = clock ();
#endif
}

void CPerformanceAnalysis::StartTiming()
{
    int hour, minute, second, msecond;

    GetCurrentTime(hour, minute, second);
    GetPreciseCurrentTime(msecond);

    m_Functions[m_CurrentFunction].ExecutionTime.Hour = hour;
    m_Functions[m_CurrentFunction].ExecutionTime.Minute = minute;
    m_Functions[m_CurrentFunction].ExecutionTime.Second = second;
    m_Functions[m_CurrentFunction].ExecutionTime.Millisecond = msecond;
}

void CPerformanceAnalysis::EndTiming()
{
    int hour, minute, second, msecond;
    GetCurrentTime(hour, minute, second);
    GetPreciseCurrentTime(msecond);

    m_Functions[m_CurrentFunction].ExecutionTime.Hour = hour - m_Functions[m_CurrentFunction].ExecutionTime.Hour;
    m_Functions[m_CurrentFunction].ExecutionTime.Minute = minute - m_Functions[m_CurrentFunction].ExecutionTime.Minute;
    m_Functions[m_CurrentFunction].ExecutionTime.Second = second - m_Functions[m_CurrentFunction].ExecutionTime.Second;
    m_Functions[m_CurrentFunction].ExecutionTime.Millisecond = msecond - m_Functions[m_CurrentFunction].ExecutionTime.Millisecond;

    //Min
    if(m_Functions[m_CurrentFunction].ExecutionTime < m_Functions[m_CurrentFunction].MinExecutionTime)
    {
        m_Functions[m_CurrentFunction].MinExecutionTime = m_Functions[m_CurrentFunction].ExecutionTime;
    }
    //Max
    if(m_Functions[m_CurrentFunction].ExecutionTime > m_Functions[m_CurrentFunction].MaxExecutionTime)
    {
        m_Functions[m_CurrentFunction].MaxExecutionTime = m_Functions[m_CurrentFunction].ExecutionTime;
    }
}

void CPerformanceAnalysis::Report_Analysis()
{
    m_File << "-----------------------------------------------------------------" << std::endl;
    m_File << "Performance analysis v " << VERSION_PERF_ANALYSIS << " - Report " << std::endl;
    m_File << "-----------------------------------------------------------------" << std::endl;

    std::map<std::string, Function_Report>::iterator _it = m_Functions.begin();
    for(; _it != m_Functions.end(); ++_it)
    {
        m_File << "-------" << _it->first << "-------" << std::endl;
        //Access time
        m_File << "As been called  " << _it->second.AccesTime;
        if(_it->second.AccesTime < 2)
        {
            m_File << " time." << std::endl;
        }
        else
        {
            m_File << " times." << std::endl;
        }

        //Execution time (for the moment only 1 instance)
        m_File << "As been executed during : " << _it->second.ExecutionTime << std::endl;

        //Min execution time
        m_File << "Minimum execution time : " << _it->second.MinExecutionTime << std::endl;
        //Max execution time
        m_File << "Maximum exectuion time : " << _it->second.MaxExecutionTime << std::endl;
    }
    m_File << "-----------------------------------------------------------------" << std::endl;
}

std::ostream& operator <<(std::ostream &os,const CPerformanceAnalysis::Time& time)
{
    os << time.Hour << "h " << time.Minute << "m " << time.Second << "s" << time.Millisecond << "ms";
    return os;
}
