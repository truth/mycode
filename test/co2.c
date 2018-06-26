#include <stdio.h>

typedef struct
{
    int i;
    int num;
    int state;
} task;

#define crBegin(state) \
        switch (state) { case 0:

#define crReturn(state, ret) \
        (state) = __LINE__; return (ret); case __LINE__:

#define crEnd() \
        }

int cb(task *t)
{
    crBegin(t->state);
    for (;;) {
        t->num = 1;
        for (t->i = 0; t->i < 20; t->i++) {
            crReturn(t->state, t->num);
            t->num += 1;
        }
    }
    crEnd();
    return -1;
}

int main()
{
    task t;
    int i;

    t.state = 0;

    for (i = 0; i < 100; i++) {
        printf("%d \n", cb(&t));
    }
    return 0;
}
