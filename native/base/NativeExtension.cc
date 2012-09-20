
/* Do not modify this file!  It is global to all native extensions. */

#include "NativeExtension.h"

#define ExportB(N, X) N##_##X
#define ExportA(N, X) ExportB(N, X)
#define Export(X) ExportA (ThisExtension, X)

#define visible __attribute__((visibility("default")))

extern "C"
{
    visible void Export(extInit) ()
    {
        Extension::init ();
    }
    
    visible void * Export(createRunObject) (void * edPtr, void * ext, RuntimeFunctions * fn)
    {
        Extension * e = new Extension ((EDITDATA *) edPtr, ext, *fn);
        
        return e;
    }
    
    visible int Export(getNumberOfConditions) ()
    {
        return Extension::getNumberOfConditions ();
    }
    
    visible void Export(destroyRunObject) (Extension * e)
    {
        delete e;
    }
    
    visible int Export(handleRunObject) (Extension * e)
    {
        return e->handleRunObject ();
    }
    
    visible void Export(action) (Extension * e, int num, void * _act)
    {
        Action act (&e->Runtime, e->ext, _act);        
        e->action (num, act);
    }
    
    visible bool Export(condition) (Extension * e, int num, void * _cnd)
    {
        Condition cnd (&e->Runtime, e->ext, _cnd);        
        return e->condition (num, cnd);
    }
    
    visible void Export(expression) (Extension * e, int num, void * _exp)
    {
        Expression exp (&e->Runtime, e->ext, _exp);
        e->expression (num, exp);
    }
}
    
