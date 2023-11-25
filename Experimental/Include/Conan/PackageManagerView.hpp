#pragma once

#include "Conan/Conan.hpp"

class PUBLIC_API_EXPORT PackageManagerView : public UI2::View
{
public:

    Map<String, String> LocalPackages;
    Map<String, Map<String, String>> EditablePackages;

    Conan conan;

    PackageManagerView()
    {
        LocalPackages = conan.GetLocalPackages();
        LoadEditablePackages();
    }

    void LoadEditablePackages()
    {
        EditablePackages = conan.GetEditablePackages();
    }

    virtual void OnDraw(Graphics::Scene &Scene) override
    {
        ImGui::Begin("Installed Packages");
        for (auto &&[package, options] : LocalPackages)
        {
            ImGui::Text("%s", package.data());
        }
        ImGui::End();

        ImGui::Begin("Editable Packages");
        if (ImGui::BeginTable("Table", 3))
        {
            ImGui::TableSetupColumn("Package", ImGuiTableColumnFlags_None);
            ImGui::TableSetupColumn("Path", ImGuiTableColumnFlags_None);
            ImGui::TableSetupColumn("Remove", ImGuiTableColumnFlags_None);

            ImGui::TableHeadersRow();
            
            /*for (int row = 0; row < 5; row++)
            {
                ImGui::TableNextRow();
                for (int col = 0; col < 3; col++)
                {
                    ImGui::TableSetColumnIndex(col);
                    ImGui::Text("Data %d,%d", row, col);
                }
            }*/
            String pathToRemove;
            size_t i = 0;
            for (auto &[package, options] : EditablePackages)
            {
                ImGui::TableNextRow();
                ImGui::TableSetColumnIndex(0);
                //ImGui::Text(package.data());
                ImGui::Text(package.data());
                ImGui::TableSetColumnIndex(1);
                ImGui::InputText(fmt::format("EditablePackages.path.{}", i).data(), &options["path"]);

                ImGui::TableSetColumnIndex(2);
                if (ImGui::Button(fmt::format("Remove##EditablePackages.{}", i).data()))
                {
                    pathToRemove = options["path"];
                }
                ++i;
            }

            if (!pathToRemove.empty())
            {
                auto String = conan.RemoveEditablePackage(pathToRemove);
                fmt::print("{}\n", String);
                LoadEditablePackages();
            }
            ImGui::EndTable();

            static String NewPackageName;
            ImGui::InputText("Name##NewPackageName", &NewPackageName);

            static String NewVersionName;
            ImGui::InputText("Version##NewVersion", &NewVersionName);

            static String NewPackagePath;
            ImGui::InputText("Path##NewPath", &NewPackagePath);

            if (ImGui::Button("Add"))
            {
                auto String = conan.AddEditablePackage(NewPackageName, NewVersionName, NewPackagePath);
                fmt::print("{}\n", String);
                LoadEditablePackages();
            }
        }
        ImGui::End();
    }
};
