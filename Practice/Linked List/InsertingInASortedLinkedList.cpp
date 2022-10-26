void insert(int data)
{
    Node *newNode = new Node(data);
    int *p = head;
    int *q = NULL;
    while (p != NULL && p->data <= data)
    {
        q = p;
        p = p->next;
    }
    newNode->next = q->next;
    q->next = newNode;
}