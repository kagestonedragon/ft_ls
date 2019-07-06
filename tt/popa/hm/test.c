#include "test.h"
#include <stdlib.h>
#include <stdio.h>

void		list(t_test *t)
{
	t_test	*p;
	t_test	*p2;

	p = (t_test *)malloc(sizeof(t_test));
	t->next = p;
	p->title = (char *)malloc(sizeof(char) * 7);
	p->title = "PRIVET\0";

	p2 = (t_test *)malloc(sizeof(t_test));
	p->next = p2;
	p2->title = (char *)malloc(sizeof(char) * 4);
	p2->title = "HUI\0";
}

int			main(void)
{
	t_test	*t;
	t_test	*p;

	t = (t_test *)malloc(sizeof(t_test));
	t->title = (char *)malloc(sizeof(char) * 5);
	t->title = "POKA\0";
	list(t);
	p = t;
	printf("%s ", p->title);
	p = p->next;
	printf("%s ", p->title);
	p = p->next;
	printf("%s\n", p->title);
	printf("%s", t->title);
	return (0);
}
