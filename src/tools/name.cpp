#include "name.h"

#if defined LEAKS
#include <leak_detector.h>
#endif

CName::CName()
{
}

CName::~CName()
{
}

const std::string& CName::getName()
{
    return m_Name;
}

void CName::setName(const std::string& _Name)
{
    m_Name.assign(_Name);
}
