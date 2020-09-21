#include <stdio.h>
#include "stack.h"
#include "stackTree.h"
#include "exp.h"
#include <stdlib.h>
#include <string.h>

int compare_opt(char stack_opt, char pending_opt)
{
    if (stack_opt == '+' || stack_opt == '-')
    {
        if (pending_opt == '+' || pending_opt == '-')
            return 0;
        return -1;
    }
    if (stack_opt == '*' || stack_opt == '/')
    {
        if (pending_opt == '^')
            return -1;
        else if (pending_opt == '+' || pending_opt == '-')
            return 1;
        else
            return 0;
    }
    if (stack_opt == '^')
    {
        if (pending_opt == '^')
            return 0;
        return 1;
    }
}

stack handle_opt(stack st, stack *sInt, stackTree *sTree, char pending_opt)
{
    if (is_empty(st))
    {
        st = push(st, pending_opt);
        return st;
    }
    else
    {
        char t = top(st);
        if (compare_opt(t, pending_opt) == -1) // priority of opt in stack in lower
        {
            st = push(st, pending_opt);
            return st;
        }
        else
        {
            if (is_empty(*sInt) == 0)
            {
                char l = top(*sInt);
                *sInt = pop(*sInt);
                if (is_empty(*sInt) == 0)
                {
                    char r = top(*sInt);
                    *sInt = pop(*sInt);

                    *sTree = push_t(*sTree, createExp(t, createArg(l), createArg(r)));
                }
                else
                {
                    exp r = top_t(*sTree);
                    *sTree = pop_t(*sTree);

                    *sTree = push_t(*sTree, createExp(t, createArg(l), r));
                }
            }

            st = pop(st);
            return handle_opt(st, sInt, sTree, pending_opt);
        }
    }
}

int main(int argc, char const *argv[])
{
    char s[100];
    scanf("%s", s);
    stack sInt = NULL;
    stackTree sTree = NULL;
    stack sOpt = NULL;

    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if ('1' <= s[i] && s[i] <= '9')
        {
            sInt = push(sInt, s[i]);
        }
        else if (s[i] == '+' || s[i] == '*' || s[i] == '-' || s[i] == '/')
        {
            sOpt = handle_opt(sOpt, &sInt, &sTree, s[i]);
        }
    }

    char lastOpt = top(sOpt);
    char lastInt = top(sInt);
    exp lastExp = top_t(sTree);

    lastExp = createExp(lastOpt, lastExp, createArg(lastInt));
    char *tmp = expToString(lastExp);
    printf("%s\n", tmp);

    free_stack(sOpt);
    free_stack(sInt);
    free_stack_t(sTree);

    return 0;
}
