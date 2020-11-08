#include "List.h"

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
	#if 0
	List *L = new List;
    int num[10] = { 0 };
    int index = 1;

    for (int i = 1; i <= 10; i++)
        num[i - 1] = i;

    for(int i = 0;i < 10;i++)
        EXPECT_EQ_INT(0, L->List_Insert(index, num[i]));

    for (int i = 1; i <= 10; i++)
        num[i - 1] = i * 20;

    index = 11;
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ_INT(0, L->List_Insert(index, num[i]));
        index++;
    }

    index = 10;
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ_INT(0, L->List_Insert(index, num[i]));
        index++;
    }

   // L->List_Show();

    delete L;

    if (L == NULL)
        std::printf("L is NULL\n");
    else {
        std::printf("L is Not NULL\n");
    }

    L = NULL;
	
	if (L == NULL)
        std::printf("L is NULL\n");
    else {
        std::printf("L is Not NULL\n");
    }
	#else
    List L;
	int A[10] = { 0 };

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

    // EXPECT_EQ_INT(0, L.List_Travel());
	#endif
	
	std::printf("%d/%d (%3.2f%%) passed\n", test_pass, test_count, test_pass * 100.0 / test_count);
    std::printf("argc:%d,argv:%s\n", argc, argv[0]);
	
	return 0;
}