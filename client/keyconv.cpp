#include "keyconv.h"



msgs::Keycode keyconv::toKeycode(int qkey) {
    switch(qkey) {
    case (Qt::Key_Backspace):
        return ::msgs::KeyBackspace;
    case (Qt::Key_Tab):
        return ::msgs::KeyTab;
    case (Qt::Key_Return):
        return ::msgs::KeyReturn;
    case (Qt::Key_Shift):
        return ::msgs::KeyLShift;
    case (Qt::Key_Control):
        return ::msgs::KeyControl;
    case (Qt::Key_Alt):
        return ::msgs::KeyAlt;
    case (Qt::Key_Meta):
        return ::msgs::KeyMeta;
    case (Qt::Key_A):
        return ::msgs::KeyA;
    case (Qt::Key_B):
        return ::msgs::KeyB;
    case (Qt::Key_C):
        return ::msgs::KeyC;
    case (Qt::Key_D):
        return ::msgs::KeyD;
    case (Qt::Key_E):
        return ::msgs::KeyE;
    case (Qt::Key_F):
        return ::msgs::KeyF;
    case (Qt::Key_G):
        return ::msgs::KeyG;
    case (Qt::Key_H):
        return ::msgs::KeyH;
    case (Qt::Key_I):
        return ::msgs::KeyI;
    case (Qt::Key_J):
        return ::msgs::KeyJ;
    case (Qt::Key_K):
        return ::msgs::KeyK;
    case (Qt::Key_L):
        return ::msgs::KeyL;
    case (Qt::Key_M):
        return ::msgs::KeyM;
    case (Qt::Key_N):
        return ::msgs::KeyN;
    case (Qt::Key_O):
        return ::msgs::KeyO;
    case (Qt::Key_P):
        return ::msgs::KeyP;
    case (Qt::Key_Q):
        return ::msgs::KeyQ;
    case (Qt::Key_R):
        return ::msgs::KeyR;
    case (Qt::Key_S):
        return ::msgs::KeyS;
    case (Qt::Key_T):
        return ::msgs::KeyT;
    case (Qt::Key_U):
        return ::msgs::KeyU;
    case (Qt::Key_V):
        return ::msgs::KeyV;
    case (Qt::Key_W):
        return ::msgs::KeyW;
    case (Qt::Key_X):
        return ::msgs::KeyX;
    case (Qt::Key_Y):
        return ::msgs::KeyY;
    case (Qt::Key_Z):
        return ::msgs::KeyZ;
    case (Qt::Key_0):
        return ::msgs::Key0;
    case (Qt::Key_1):
        return ::msgs::Key1;
    case (Qt::Key_2):
        return ::msgs::Key2;
    case (Qt::Key_3):
        return ::msgs::Key3;
    case (Qt::Key_4):
        return ::msgs::Key4;
    case (Qt::Key_5):
        return ::msgs::Key5;
    case (Qt::Key_6):
        return ::msgs::Key6;
    case (Qt::Key_7):
        return ::msgs::Key7;
    case (Qt::Key_8):
        return ::msgs::Key8;
    case (Qt::Key_9):
        return ::msgs::Key9;
    case (Qt::Key_Pause):
        return ::msgs::KeyPause;
    case (Qt::Key_CapsLock):
        return ::msgs::KeyCapsLock;
    case (Qt::Key_Escape):
        return ::msgs::KeyEscape;
    case (Qt::Key_Space):
        return ::msgs::KeySpace;
    case (Qt::Key_PageUp):
        return ::msgs::KeyPageUp;
    case (Qt::Key_PageDown):
        return ::msgs::KeyPageDown;
    case (Qt::Key_End):
        return ::msgs::KeyEnd;
    case (Qt::Key_Home):
        return ::msgs::KeyHome;
    case (Qt::Key_Left):
        return ::msgs::KeyLeft;
    case (Qt::Key_Up):
        return ::msgs::KeyUp;
    case (Qt::Key_Right):
        return ::msgs::KeyRight;
    case (Qt::Key_Down):
        return ::msgs::KeyDown;
    case (Qt::Key_Select):
        return ::msgs::KeySelect;
    case (Qt::Key_Print):
        return ::msgs::KeyPrint;
    case (Qt::Key_Execute):
        return ::msgs::KeyExecute;
    case (Qt::Key_Insert):
        return ::msgs::KeyInsert;
    case (Qt::Key_Delete):
        return ::msgs::KeyDelete;
    case (Qt::Key_Help):
        return ::msgs::KeyHelp;
    case (Qt::Key_Sleep):
        return ::msgs::KeySleep;
    case (Qt::Key_0+Qt::KeypadModifier):
        return ::msgs::KeyKeypad0;
    case (Qt::Key_1+Qt::KeypadModifier):
        return ::msgs::KeyKeypad1;
    case (Qt::Key_2+Qt::KeypadModifier):
        return ::msgs::KeyKeypad2;
    case (Qt::Key_3+Qt::KeypadModifier):
        return ::msgs::KeyKeypad3;
    case (Qt::Key_4+Qt::KeypadModifier):
        return ::msgs::KeyKeypad4;
    case (Qt::Key_5+Qt::KeypadModifier):
        return ::msgs::KeyKeypad5;
    case (Qt::Key_6+Qt::KeypadModifier):
        return ::msgs::KeyKeypad6;
    case (Qt::Key_7+Qt::KeypadModifier):
        return ::msgs::KeyKeypad7;
    case (Qt::Key_8+Qt::KeypadModifier):
        return ::msgs::KeyKeypad8;
    case (Qt::Key_9+Qt::KeypadModifier):
        return ::msgs::KeyKeypad9;
    case (Qt::Key_Asterisk+Qt::KeypadModifier):
        return ::msgs::KeyKeypadAsterisk;
    case (Qt::Key_Plus+Qt::KeypadModifier):
        return ::msgs::KeyKeypadPlus;
    case (Qt::Key_Comma+Qt::KeypadModifier):
        return ::msgs::KeyKeypadComma;
    case (Qt::Key_Minus+Qt::KeypadModifier):
        return ::msgs::KeyKeypadMinus;
    case (Qt::Key_Period+Qt::KeypadModifier):
        return ::msgs::KeyKeypadPeriod;
    case (Qt::Key_Slash+Qt::KeypadModifier):
        return ::msgs::KeyKeypadSlash;
    case (Qt::Key_F1):
        return ::msgs::KeyF1;
    case (Qt::Key_F2):
        return ::msgs::KeyF2;
    case (Qt::Key_F3):
        return ::msgs::KeyF3;
    case (Qt::Key_F4):
        return ::msgs::KeyF4;
    case (Qt::Key_F5):
        return ::msgs::KeyF5;
    case (Qt::Key_F6):
        return ::msgs::KeyF6;
    case (Qt::Key_F7):
        return ::msgs::KeyF7;
    case (Qt::Key_F8):
        return ::msgs::KeyF8;
    case (Qt::Key_F9):
        return ::msgs::KeyF9;
    case (Qt::Key_F10):
        return ::msgs::KeyF10;
    case (Qt::Key_F11):
        return ::msgs::KeyF11;
    case (Qt::Key_F12):
        return ::msgs::KeyF12;
    case (Qt::Key_F13):
        return ::msgs::KeyF13;
    case (Qt::Key_F14):
        return ::msgs::KeyF14;
    case (Qt::Key_F15):
        return ::msgs::KeyF15;
    case (Qt::Key_F16):
        return ::msgs::KeyF16;
    case (Qt::Key_F17):
        return ::msgs::KeyF17;
    case (Qt::Key_F18):
        return ::msgs::KeyF18;
    case (Qt::Key_F19):
        return ::msgs::KeyF19;
    case (Qt::Key_F20):
        return ::msgs::KeyF20;
    case (Qt::Key_F21):
        return ::msgs::KeyF21;
    case (Qt::Key_F22):
        return ::msgs::KeyF22;
    case (Qt::Key_F23):
        return ::msgs::KeyF23;
    case (Qt::Key_F24):
        return ::msgs::KeyF24;
    case (Qt::Key_NumLock):
        return ::msgs::KeyNumLock;
    case (Qt::Key_ScrollLock):
        return ::msgs::KeyScrollLock;
    case (Qt::Key_Back):
        return ::msgs::KeyBack;
    case (Qt::Key_Forward):
        return ::msgs::KeyForward;
    case (Qt::Key_Refresh):
        return ::msgs::KeyRefresh;
    case (Qt::Key_Stop):
        return ::msgs::KeyStop;
    case (Qt::Key_Search):
        return ::msgs::KeySearch;
    case (Qt::Key_Favorites):
        return ::msgs::KeyFavorites;
    case (Qt::Key_HomePage):
        return ::msgs::KeyHomePage;
    case (Qt::Key_VolumeMute):
        return ::msgs::KeyVolumeMute;
    case (Qt::Key_VolumeDown):
        return ::msgs::KeyVolumeDown;
    case (Qt::Key_VolumeUp):
        return ::msgs::KeyVolumeUp;
    case (Qt::Key_MediaNext):
        return ::msgs::KeyMediaNext;
    case (Qt::Key_MediaPrevious):
        return ::msgs::KeyMediaPrev;
    case (Qt::Key_MediaStop):
        return ::msgs::KeyMediaStop;
    case (Qt::Key_MediaTogglePlayPause):
        return ::msgs::KeyMediaTogglePlayPause;
    case (Qt::Key_Play):
        return ::msgs::KeyPlay;
    case (Qt::Key_Zoom):
        return ::msgs::KeyZoom;

    default:
        return ::msgs::KeyUnknown;
    }
}

int keyconv::toQtKey(::msgs::Keycode proto_key) {
    switch(proto_key) {
    case ::msgs::KeyBackspace:
        return Qt::Key_Backspace;
    case ::msgs::KeyTab:
        return Qt::Key_Tab;
    case ::msgs::KeyReturn:
        return Qt::Key_Return;
    case ::msgs::KeyLShift:
        return Qt::Key_Shift;
    case ::msgs::KeyControl:
        return Qt::Key_Control;
    case ::msgs::KeyAlt:
        return Qt::Key_Alt;
    case ::msgs::KeyMeta:
        return Qt::Key_Meta;
    case ::msgs::KeyA:
        return Qt::Key_A;
    case ::msgs::KeyB:
        return Qt::Key_B;
    case ::msgs::KeyC:
        return Qt::Key_C;
    case ::msgs::KeyD:
        return Qt::Key_D;
    case ::msgs::KeyE:
        return Qt::Key_E;
    case ::msgs::KeyF:
        return Qt::Key_F;
    case ::msgs::KeyG:
        return Qt::Key_G;
    case ::msgs::KeyH:
        return Qt::Key_H;
    case ::msgs::KeyI:
        return Qt::Key_I;
    case ::msgs::KeyJ:
        return Qt::Key_J;
    case ::msgs::KeyK:
        return Qt::Key_K;
    case ::msgs::KeyL:
        return Qt::Key_L;
    case ::msgs::KeyM:
        return Qt::Key_M;
    case ::msgs::KeyN:
        return Qt::Key_N;
    case ::msgs::KeyO:
        return Qt::Key_O;
    case ::msgs::KeyP:
        return Qt::Key_P;
    case ::msgs::KeyQ:
        return Qt::Key_Q;
    case ::msgs::KeyR:
        return Qt::Key_R;
    case ::msgs::KeyS:
        return Qt::Key_S;
    case ::msgs::KeyT:
        return Qt::Key_T;
    case ::msgs::KeyU:
        return Qt::Key_U;
    case ::msgs::KeyV:
        return Qt::Key_V;
    case ::msgs::KeyW:
        return Qt::Key_W;
    case ::msgs::KeyX:
        return Qt::Key_X;
    case ::msgs::KeyY:
        return Qt::Key_Y;
    case ::msgs::KeyZ:
        return Qt::Key_Z;
    case ::msgs::Key0:
        return Qt::Key_0;
    case ::msgs::Key1:
        return Qt::Key_1;
    case ::msgs::Key2:
        return Qt::Key_2;
    case ::msgs::Key3:
        return Qt::Key_3;
    case ::msgs::Key4:
        return Qt::Key_4;
    case ::msgs::Key5:
        return Qt::Key_5;
    case ::msgs::Key6:
        return Qt::Key_6;
    case ::msgs::Key7:
        return Qt::Key_7;
    case ::msgs::Key8:
        return Qt::Key_8;
    case ::msgs::Key9:
        return Qt::Key_9;
    case ::msgs::KeyPause:
        return Qt::Key_Pause;
    case ::msgs::KeyCapsLock:
        return Qt::Key_CapsLock;
    case ::msgs::KeyEscape:
        return Qt::Key_Escape;
    case ::msgs::KeySpace:
        return Qt::Key_Space;
    case ::msgs::KeyPageUp:
        return Qt::Key_PageUp;
    case ::msgs::KeyPageDown:
        return Qt::Key_PageDown;
    case ::msgs::KeyEnd:
        return Qt::Key_End;
    case ::msgs::KeyHome:
        return Qt::Key_Home;
    case ::msgs::KeyLeft:
        return Qt::Key_Left;
    case ::msgs::KeyUp:
        return Qt::Key_Up;
    case ::msgs::KeyRight:
        return Qt::Key_Right;
    case ::msgs::KeyDown:
        return Qt::Key_Down;
    case ::msgs::KeySelect:
        return Qt::Key_Select;
    case ::msgs::KeyPrint:
        return Qt::Key_Print;
    case ::msgs::KeyExecute:
        return Qt::Key_Execute;
    case ::msgs::KeyInsert:
        return Qt::Key_Insert;
    case ::msgs::KeyDelete:
        return Qt::Key_Delete;
    case ::msgs::KeyHelp:
        return Qt::Key_Help;
    case ::msgs::KeySleep:
        return Qt::Key_Sleep;
    case ::msgs::KeyKeypad0:
        return Qt::Key_0+Qt::KeypadModifier;
    case ::msgs::KeyKeypad1:
        return Qt::Key_1+Qt::KeypadModifier;
    case ::msgs::KeyKeypad2:
        return Qt::Key_2+Qt::KeypadModifier;
    case ::msgs::KeyKeypad3:
        return Qt::Key_3+Qt::KeypadModifier;
    case ::msgs::KeyKeypad4:
        return Qt::Key_4+Qt::KeypadModifier;
    case ::msgs::KeyKeypad5:
        return Qt::Key_5+Qt::KeypadModifier;
    case ::msgs::KeyKeypad6:
        return Qt::Key_6+Qt::KeypadModifier;
    case ::msgs::KeyKeypad7:
        return Qt::Key_7+Qt::KeypadModifier;
    case ::msgs::KeyKeypad8:
        return Qt::Key_8+Qt::KeypadModifier;
    case ::msgs::KeyKeypad9:
        return Qt::Key_9+Qt::KeypadModifier;
    case ::msgs::KeyKeypadAsterisk:
        return Qt::Key_Asterisk+Qt::KeypadModifier;
    case ::msgs::KeyKeypadPlus:
        return Qt::Key_Plus+Qt::KeypadModifier;
    case ::msgs::KeyKeypadComma:
        return Qt::Key_Comma+Qt::KeypadModifier;
    case ::msgs::KeyKeypadMinus:
        return Qt::Key_Minus+Qt::KeypadModifier;
    case ::msgs::KeyKeypadPeriod:
        return Qt::Key_Period+Qt::KeypadModifier;
    case ::msgs::KeyKeypadSlash:
        return Qt::Key_Slash+Qt::KeypadModifier;
    case ::msgs::KeyF1:
        return Qt::Key_F1;
    case ::msgs::KeyF2:
        return Qt::Key_F2;
    case ::msgs::KeyF3:
        return Qt::Key_F3;
    case ::msgs::KeyF4:
        return Qt::Key_F4;
    case ::msgs::KeyF5:
        return Qt::Key_F5;
    case ::msgs::KeyF6:
        return Qt::Key_F6;
    case ::msgs::KeyF7:
        return Qt::Key_F7;
    case ::msgs::KeyF8:
        return Qt::Key_F8;
    case ::msgs::KeyF9:
        return Qt::Key_F9;
    case ::msgs::KeyF10:
        return Qt::Key_F10;
    case ::msgs::KeyF11:
        return Qt::Key_F11;
    case ::msgs::KeyF12:
        return Qt::Key_F12;
    case ::msgs::KeyF13:
        return Qt::Key_F13;
    case ::msgs::KeyF14:
        return Qt::Key_F14;
    case ::msgs::KeyF15:
        return Qt::Key_F15;
    case ::msgs::KeyF16:
        return Qt::Key_F16;
    case ::msgs::KeyF17:
        return Qt::Key_F17;
    case ::msgs::KeyF18:
        return Qt::Key_F18;
    case ::msgs::KeyF19:
        return Qt::Key_F19;
    case ::msgs::KeyF20:
        return Qt::Key_F20;
    case ::msgs::KeyF21:
        return Qt::Key_F21;
    case ::msgs::KeyF22:
        return Qt::Key_F22;
    case ::msgs::KeyF23:
        return Qt::Key_F23;
    case ::msgs::KeyF24:
        return Qt::Key_F24;
    case ::msgs::KeyNumLock:
        return Qt::Key_NumLock;
    case ::msgs::KeyScrollLock:
        return Qt::Key_ScrollLock;
    case ::msgs::KeyBack:
        return Qt::Key_Back;
    case ::msgs::KeyForward:
        return Qt::Key_Forward;
    case ::msgs::KeyRefresh:
        return Qt::Key_Refresh;
    case ::msgs::KeyStop:
        return Qt::Key_Stop;
    case ::msgs::KeySearch:
        return Qt::Key_Search;
    case ::msgs::KeyFavorites:
        return Qt::Key_Favorites;
    case ::msgs::KeyHomePage:
        return Qt::Key_HomePage;
    case ::msgs::KeyVolumeMute:
        return Qt::Key_VolumeMute;
    case ::msgs::KeyVolumeDown:
        return Qt::Key_VolumeDown;
    case ::msgs::KeyVolumeUp:
        return Qt::Key_VolumeUp;
    case ::msgs::KeyMediaNext:
        return Qt::Key_MediaNext;
    case ::msgs::KeyMediaPrev:
        return Qt::Key_MediaPrevious;
    case ::msgs::KeyMediaStop:
        return Qt::Key_MediaStop;
    case ::msgs::KeyMediaTogglePlayPause:
        return Qt::Key_MediaTogglePlayPause;
    case ::msgs::KeyPlay:
        return Qt::Key_Play;
    case ::msgs::KeyZoom:
        return Qt::Key_Zoom;

    default:
        return Qt::Key_unknown;
    }
}