//
// Created by Silas Ruffner on 30.01.24.
//

#ifndef WS_EMULATOR_HEXEDITORVIEW_H
#define WS_EMULATOR_HEXEDITORVIEW_H

#include "../model/memory"

class HexEditorView {
    HexEditorView();

    void update();

private:
    MemoryModel& memory_model;

};


#endif //WS_EMULATOR_HEXEDITORVIEW_H
