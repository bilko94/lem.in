#include "js.h"

registry *reg = NULL;

int push(int id, int var){
	registry *data_head = find_data_head(id);
	if (data_head == NULL)
		data_head = build_head(1,id);
	array *arr = data_head->arr;
	if (!arr){
		data_head->arr = malloc_push(var);
	} else {
		while (arr->next)
			arr = arr->next;
		arr->next = malloc_push(var);
	}
	return (data_head->id); 
}

int pop(int id){
	registry *data_head = find_data_head(id);
	array *temp = NULL;
	int res = 0;

	if (data_head){
		temp = data_head->arr;
		if (temp){
			if (temp->next){
				while (temp->next->next)
					temp = temp->next;
				res = temp->next->v;
				free(temp->next);
				temp->next = NULL;
			} else {
				res = temp->v;
				data_head->arr = NULL;
				free(temp);
			}
			return res;
		}
	} else
		return (-1);
	
}

registry *build_head(int vtype, int id){
	registry *head = reg;
	registry *new = init_registry();

	while (head->next)
		head = head->next;
	head->next = new;
	new->id = id;
	new->vtype = vtype;
	return (new);
}

registry *find_data_head(int data_id){
	registry *head = reg;

	while (head){
		if (head->id == data_id)
			return head;
		head = head->next;
	}
	return (NULL);
	
}

registry *init_registry(){
	registry *new = NULL;

	if ((new = (registry *)malloc(sizeof(registry)))){
		new->id = 0;
		new->next = NULL;
		new->vtype = 0;
		new->arr = NULL;
	}
	return new;
}

array *malloc_push(int value){
	array *new = NULL;

	if ((new = (array *)malloc(sizeof(array)))){
		new->v = value;
		new->next = NULL;
	}
	return (new);
}

void print_arr(int id){
	registry *temp = find_data_head(id);
	array *arr = NULL;
	if (temp)
		arr = temp->arr;
	while (arr){
		printf("%d ", arr->v);
		arr = arr->next;
	}
	printf("\n");
}

void print_head(){
	registry *temp = reg;
	while (temp){
		printf("%p %d\n", temp, temp->id);
		temp = temp->next;
	}
	
}

void end(registry *reg){
	if (reg)
		if (reg->next)
			end(reg->next);
	end_array(reg->arr);
	free(reg);
}

void end_array(array *arr){
	if (arr)
		if (arr->next)
			end_array(arr->next);
	free(arr);
}