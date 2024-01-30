//
// Created by Silas Ruffner on 30.01.24.
//

#ifndef WS_EMULATOR_CODE_EDITOR_H
#define WS_EMULATOR_CODE_EDITOR_H

#include "../model/text.h"
#include "../view/codeEditorView.h"

class CodeEditorController {

private:
    TextModel& text_model;
    CodeEditorView& code_view;
};


#endif //WS_EMULATOR_CODE_EDITOR_H
