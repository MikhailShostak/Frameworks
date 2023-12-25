//        Author: Insane Team
//          File: OSProjectEntryDataObject.h
// Creation date: 01/11/17 04:50:15
//     Copyright: Insane Team, 2016. All rights reseved.

#pragma once

#include <LegacyData.hpp>
#include <LegacyFoundation.hpp>

//       Class: OSProjectEntryDataObject
//        Base: ADataObject
//        Link:
// Description:

class OSProjectEntryDataObject : public ADataObject
{
public:
    typedef OSProjectEntryDataObject This;
    typedef ADataObject Super;
    typedef class OSProjectEntryDataObjectEntity Entity;

    struct Data
    {
        String package;
        String path;
    };

private:
    Data data;

public:
    static const Entity &getStaticEntity();
    const ADataEntity &getEntity() const override;
    void fetch() override;

public:
    const String &getPackage() const;
    void setPackage(const String &package);
    void setPackage(String &&package);
    void fetchPackage();
private:
    void commitPackage();

public:
    const String &getPath() const;
    void setPath(const String &path);
    void setPath(String &&path);
    void fetchPath();
private:
    void commitPath();
};

class OSProjectEntryDataObjectEntity : public ADataEntity
{
    using ADataEntity::ADataEntity;

    static String PackageFieldName;
    static String PathFieldName;

public:
    typedef OSProjectEntryDataObject DataType;

    static const String &getPackageFieldName();
    typedef StringDataField<DataType, PackageFieldName, &OSProjectEntryDataObject::getPackage, &OSProjectEntryDataObject::setPackage> PackageField;

    static const String &getPathFieldName();
    typedef StringDataField<DataType, PathFieldName, &OSProjectEntryDataObject::getPath, &OSProjectEntryDataObject::setPath> PathField;
};
