#include "test/test_NormalWork.h"
#include "test/test_multiMaintain.h"
#include "test/test_multiDispatch.h"
#include "test/test_worker.h"
#include "test/test_report.h"
#include "test/test_dispatch.h"

int main(){
    cout << "test_NormalWork : ";
    test_NormalWork();
    cout << " Successed! " << endl;

    cout << "test_multiDispatch : ";
    test_multiDispatch();
    cout << " Successed! " << endl;

    cout << "test_multiMaintain : ";
    test_multiMaintain();
    cout << " Successed! " << endl;

    cout << "test_worker : ";
    test_worker();
    cout << " Successed! " << endl;

    cout << "test_report : ";
    test_report();
    cout << " Successed! " << endl;

    cout << "test_dispatch : ";
    test_Dispatch();
    cout << " Successed! " << endl;
}