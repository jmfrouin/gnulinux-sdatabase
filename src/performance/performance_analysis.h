/*
-------------------------------------------------------------------------
Project : sdatabase
-------------------------------------------------------------------------
Creator : Frouin Jean-Michel
-------------------------------------------------------------------------
$Date$
$Rev$
$Author$
-------------------------------------------------------------------------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; version 2 of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
-------------------------------------------------------------------------
*/

#ifndef _PERFORMANCE_ANALYSIS_H_
#define _PERFORMANCE_ANALYSIS_H_

#include <string>
#include <iostream>
#include <map>
#include <fstream>

#define VERSION_PERF_ANALYSIS 0.01

/*!
 * @brief Performance analysis tool.
 */
class CPerformanceAnalysis
{
    public:
        /*!
         * @brief	Default constructor.
         */
        CPerformanceAnalysis();
        /*!
         * @brief	Destructor.
         */
        ~CPerformanceAnalysis();

        /*!
         * @brief	Add function to performance analysis.
         * @param	_Name Name of function to investigate.
         */
        int AddFunction(std::string _Name);
        /*!
         * @brief	Start timing.
         */
        void StartTiming();
        /*!
         * @brief	Stop timing.
         */
        void EndTiming();

    private:
        /*!
         * @brief	Write analysis report.
         */
        void Report_Analysis();
        /*!
         * @brief	Retrieve current time.
         * @param	_hour Current hour.
         * @param	_minute Current minute.
         * @param	_second Current second.
         */
        void GetCurrentTime(int& _hour, int& _minute, int& _second);
        /*!
         * @brief	Retrieve current time in millisecond.
         * @param	_millisecond Current millisecond.
         */
        void GetPreciseCurrentTime(int& _millisecond);

    public:
        /*!
         * @brief A structure for time manipulations.
         */
        struct Time
        {
            Time():
            Hour(0),Minute(0),Second(0),Millisecond(0)
                {}

            Time(int h, int m, int s, int ms):
            Hour(h),Minute(m),Second(s),Millisecond(ms)
                {}

            bool operator < (const Time& time)
            {
                if( (Hour < time.Hour) ||
                    ((Hour == time.Hour) && (Minute < time.Minute)) ||
                    ((Hour == time.Hour) && (Minute == time.Minute) && (Second < time.Second)) ||
                    ((Hour == time.Hour) && (Minute == time.Minute) && (Second == time.Second) && (Millisecond < time.Millisecond)) )
                    return true;
                else
                    return false;
            }

            bool operator > (const Time& time)
            {
                if( (Hour > time.Hour) ||
                    ((Hour == time.Hour) && (Minute > time.Minute)) ||
                    ((Hour == time.Hour) && (Minute == time.Minute) && (Second > time.Second)) ||
                    ((Hour == time.Hour) && (Minute == time.Minute) && (Second == time.Second) && (Millisecond > time.Millisecond)) )
                    return true;
                else
                    return false;
            }

            int            Hour;
            int            Minute;
            int            Second;
            int            Millisecond;
        };

    private:
        /*!
         * @brief Report structure for simply manipulation of informations.
         */
        struct Function_Report
        {
            Function_Report():AccesTime(0), MinExecutionTime(23,59,59,999), MaxExecutionTime(0,0,0,0)
                {}

            int         AccesTime;
            std::string FunctionName;
            Time        MinExecutionTime;
            Time        MaxExecutionTime;
            Time        ExecutionTime;
            Time        Average;
        };

        std::map<std::string, Function_Report>          m_Functions;
        std::string                                     m_CurrentFunction;
        std::ofstream                                   m_File;
};

std::ostream& operator <<(std::ostream &os,const CPerformanceAnalysis::Time& time);
#endif                           //_PERFORMANCE_ANALYSIS_H_

extern CPerformanceAnalysis* g_pa;
