#include "test/test_NormalWork.h"
#include "test/test_multiMaintain.h"
#include "test/test_multiDispatch.h"
#include "test/test_worker.h"

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
}