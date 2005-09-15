#include "stdafx.h"

#include "Map.h"

#include "ActionButton.h"
#include "Datafile.h"

#include "GameInterface/Messages.h"

static void LoadMap()
{
	wxFileDialog dlg (NULL, wxFileSelectorPromptStr, Datafile::GetDataDirectory()+_T("/mods/official/maps/scenarios"),
		_T(""), _T("PMP files (*.pmp)|*.pmp|All files (*.*)|*.*"), wxOPEN);
	if (dlg.ShowModal() == wxID_OK)
	{
		std::wstring map = dlg.GetFilename().c_str();
		POST_COMMAND(LoadMap(map));
	}

	// TODO: Make this a non-undoable command
}

static void GenerateMap()
{
	POST_COMMAND(GenerateMap(9));
}

MapSidebar::MapSidebar(wxWindow* parent)
	: Sidebar(parent)
{
	// TODO: Less ugliness
	// TODO: Intercept arrow keys and send them to the GL window

	m_MainSizer->Add(new ActionButton(this, _T("Load existing map"), &LoadMap));
	m_MainSizer->Add(new ActionButton(this, _T("Generate empty map"), &GenerateMap));
}
