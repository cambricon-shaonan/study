#include <string.h>
#include <stdio.h>
#include <stdlib.h>
struct list {
	int id;
	char data[20];
	struct list *next;
};

static struct list *list_head =NULL;

static int list_id = 0;

static void list_add(struct list **head, struct list *list)
{
	struct list *temp;
	if(*head == NULL)
	{
		*head = list;
		(*head)->next = NULL;
	}else {
		temp = *head;
		while(temp){
			if(temp->next == NULL)
			{
				temp->next = list;
				list->next = NULL;
			}
			temp = temp->next;
		}
	}
}

static void list_print(struct list **head)
{
	struct list *temp;
	temp = *head;
	printf("list information:\n");
	while(temp)
	{
		printf("id:%d----%s\n", temp->id, temp->data);
		temp = temp->next;
	}
}

void list_change(struct list **head, int id)
{
	struct list *tmp;
	tmp = *head;
	while(tmp)
	{
		if(tmp->id==id)
		{
			memset(tmp->data,0,sizeof(tmp->data));
			strcpy(tmp->data,"ok ok");
		}
		tmp = tmp->next;
	}
}
void list_del(struct list **head, int id)
{
	struct list *tmp,*p;
	tmp = *head;
	if(tmp == NULL){
		printf("kong listi\n");
	}
	if(tmp->id == id)
	{
		*head = tmp->next;
	}else{
		while(tmp->next){     //be cautious here 
			p = tmp;
			tmp = tmp->next;
			if(tmp->id == id)
			{
				p->next = tmp->next;
			}
		}
	}

}
int main(int argc, char *argv[])
{
	int i = 0;
	struct list *lists = NULL;
	lists = malloc(sizeof(struct list) * 10);
	if(lists == NULL)
	{
		printf("malloc error!\n");
		return -1;
	}

	for(i = 0; i<10; i++)
	{
		lists[i].id = list_id++;
		sprintf(lists[i].data, "fuckit_%d", i);
		list_add(&list_head, &lists[i]);
	}
	list_change(&list_head,2);
	list_del(&list_head,5);
	list_print(&list_head);
	free(lists);
	return 0;
}

