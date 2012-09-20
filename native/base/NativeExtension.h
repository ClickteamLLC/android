
/* Do not modify this file!  It is global to all native extensions. */

#ifndef _ExtensionClass

    #include "../../android/jni/RuntimeNative.h"

    const int REFLAG_DISPLAY = 1;
    const int REFLAG_ONESHOT = 2;

    struct ACE
    {
        RuntimeFunctions * fn;
        void * ext;
        
        RuntimeFunctions::string strings [8];
        int stringIndex;
        
        inline const char * trackString (RuntimeFunctions::string s)
        {
            strings [stringIndex ++] = s;
            return s.ptr;
        }        
        
        inline ACE ()
        {
            stringIndex = 0;
        }
        
        inline ~ ACE ()
        {
            while (-- stringIndex >= 0)
                fn->freeString (ext, strings [stringIndex]);
        }
    };
    
    class Action : public ACE
    {
        void * act;
        
    public:

        inline Action (RuntimeFunctions * fn, void * ext, void * _act)
            : act (_act)
        {
            this->ext = ext;
            this->fn = fn;
        }
        
        inline int getParamExpression ()
        {   return fn->act_getParamExpression (ext, act);
        }
        
        inline const char * getParamExpString ()
        {   return trackString (fn->act_getParamExpString (ext, act));
        }
        
        inline float getParamExpFloat ()
        {   return fn->act_getParamExpFloat (ext, act);
        }
    };

    class Condition : public ACE
    {
        void * cnd;
        
    public:

        inline Condition (RuntimeFunctions * fn, void * ext, void * _cnd)
            : cnd (_cnd)
        {
            this->ext = ext;
            this->fn = fn;
        }
        
        inline int getParamExpression ()
        {   return fn->cnd_getParamExpression (ext, cnd);
        }
        
        inline const char * getParamExpString ()
        {   return trackString (fn->cnd_getParamExpString (ext, cnd));
        }
        
        inline float getParamExpFloat ()
        {   return fn->cnd_getParamExpFloat (ext, cnd);
        }
    };

    class Expression : public ACE
    {
        void * exp;
        
    public:

        inline Expression (RuntimeFunctions * fn, void * ext, void * _exp)
            : exp (_exp)
        {
            this->ext = ext;
            this->fn = fn;
        }
        
        inline int getParamInt ()
        {   return fn->exp_getParamInt (ext, exp);
        }
        
        inline const char * getParamString ()
        {   return trackString (fn->exp_getParamString (ext, exp));
        }
        
        inline float getParamFloat ()
        {   return fn->exp_getParamFloat (ext, exp);
        }
        
        inline void setReturnInt (int value)
        {   fn->exp_setReturnInt (ext, exp, value);
        }
        
        inline void setReturnString (const char * value)
        {   fn->exp_setReturnString (ext, exp, value);
        }
        
        inline void setReturnFloat (float value)
        {   fn->exp_setReturnFloat (ext, exp, value);
        }
    };

    struct EDITDATA;

    #define _ExtensionClass
    #include "Extension.h"
    #undef _ExtensionClass
    
#else

    RuntimeFunctions &Runtime;
    void * ext;
    
    Extension (EDITDATA * edPtr, void *, RuntimeFunctions &);
    ~ Extension ();
  
    static void init ();
    static int getNumberOfConditions ();
    
    int handleRunObject ();
    
    void action     (int num, Action &);
    bool condition  (int num, Condition &);
    void expression (int num, Expression &);
    
    inline void generateEvent (int code, int param = 0)
    {
        Runtime.generateEvent (ext, code, param);
    }
    
#endif



