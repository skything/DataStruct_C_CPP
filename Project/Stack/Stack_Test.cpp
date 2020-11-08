#include"Stack.h"

#ifdef _DEBUG
#define DEBUG_CLIENTBLOCK new( _CLIENT_BLOCK, __FILE__, __LINE__)
#else
#define DEBUG_CLIENTBLOCK
#endif // _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#define new DEBUG_CLIENTBLOCK

#endif // _DEBUG

static int main_ret = 0;
static int test_count = 0;
static int test_pass = 0;

#define EXPECT_EQ_BASE(equality, expect, actual, format) \
    do {\
        test_count++;\
        if (equality)\
            test_pass++;\
        else {\
            fprintf(stderr, "%s:%d: expect: " format " actual: " format "\n", __FILE__, __LINE__, expect, actual);\
            main_ret = 1;\
        }\
    } while(0)

#define EXPECT_EQ_INT(expect, actual) EXPECT_EQ_BASE((expect) == (actual), expect, actual, "%d")

int main(int argc,char *argv[])
{
    _Stack s;
    int A[10] = { 0 };
    List L;

    for (int i = 1; i <= 10; i++) {
        A[i-1] = i + 1;
        EXPECT_EQ_INT(0, L.List_HeadInsert(A[i-1]));
    }

    for(int i = 0;i < 10;i++)
        std::printf("%d\n", List::List_GetData(L[i]));

    for (int i = 0; i < 10; i++) {
        A[i] = 100 + i;
        EXPECT_EQ_INT(0, L.List_ChangeValue(i, A[i]));
    }


    for (int i = 0; i < 10; i++)
        std::printf("%d\n", List::List_GetData(L[i]));

    int Index = 0;       
    EXPECT_EQ_INT(0, L.List_Travel());


    for (int i = 0; i < 10; i++){
        A[i] = i + 1;
        EXPECT_EQ_INT(0, s.push(A[i]));
    }

    int B[10];
    for (int i = 0; i < 10; i++)
        EXPECT_EQ_INT(0, s.pop(B[i]));

    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    std::printf("%d/%d (%3.2f%%) passed\n", test_pass, test_count, test_pass * 100.0 / test_count);
    std::printf("argc:%d,argv:%s\n", argc, argv[0]);

    return 0;
}