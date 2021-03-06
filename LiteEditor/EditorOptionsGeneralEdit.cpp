#include "EditorOptionsGeneralEdit.h"
#include "optionsconfig.h"
#include "editor_config.h"

EditorOptionsGeneralEdit::EditorOptionsGeneralEdit(wxWindow* parent)
    : EditorOptionsGeneralEditBase(parent)
{
    m_pgMgrEdit->GetGrid()->SetPropertyAttributeAll(wxPG_BOOL_USE_CHECKBOX, true);
    OptionsConfigPtr options = EditorConfigST::Get()->GetOptions();
    m_pgPropSmartCurly->SetValue(options->GetAutoAddMatchedCurlyBraces());
    m_pgPropSmartParentheses->SetValue(options->GetAutoAddMatchedNormalBraces());
    m_pgPropSmartQuotes->SetValue(options->GetAutoCompleteDoubleQuotes());
    m_pgPropWrapBrackets->SetValue(options->IsWrapSelectionBrackets());
    m_pgPropWrapQuotes->SetValue(options->IsWrapSelectionWithQuotes());
}

EditorOptionsGeneralEdit::~EditorOptionsGeneralEdit()
{
}

void EditorOptionsGeneralEdit::OnValueChanged(wxPropertyGridEvent& event)
{
    event.Skip();
}

void EditorOptionsGeneralEdit::Save(OptionsConfigPtr options)
{
    options->SetAutoAddMatchedCurlyBraces(m_pgPropSmartCurly->GetValue().GetBool());
    options->SetAutoAddMatchedNormalBraces(m_pgPropSmartParentheses->GetValue().GetBool());
    options->SetAutoCompleteDoubleQuotes(m_pgPropSmartQuotes->GetValue().GetBool());
    options->SetWrapSelectionBrackets(m_pgPropWrapBrackets->GetValue().GetBool());
    options->SetWrapSelectionWithQuotes(m_pgPropWrapQuotes->GetValue().GetBool());
}
