#pragma once

#include "AString.h"

class PUBLIC_API_EXPORT MIMETypeDataBase
{
public:



};

class PUBLIC_API_EXPORT AMIMEType
{

    String contentType;
    String parentType;

public:

    AMIMEType(const String &contentType = String(), const String &parentType = "text/plain"):
        contentType(contentType),
        parentType(parentType)
    {}

    const String &getContentType() const
    {
        return contentType;
    }

    const String &getParentType() const
    {
        return parentType;
    }

};
