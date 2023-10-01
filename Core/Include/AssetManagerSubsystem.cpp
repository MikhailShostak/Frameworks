
namespace Core
{

void AssetManagerSubsystem::Load()
{
    for (auto &Folder : Folders)
    {
        RuntimeAssetStorage::LoadFolder(Folder, ".yaml");
    }
}

}
