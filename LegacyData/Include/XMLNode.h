#pragma once

#include <LegacyFoundation.hpp>

namespace XMLTemplates
{
    struct PUBLIC_API_EXPORT XMLNode
    {
        String name;
        Map<String, String> attributes;
        String content;
        Array<XMLNode> nodes;
    };
}

using XMLNode = XMLTemplates::XMLNode;
//TODO: Add XMLNode which will store reference
//using XMLReferencedNode = XMLTemplates::XMLNode<UniqueReference<XMLTemplates::XMLNode<::XMLReferencedNode>>>;
