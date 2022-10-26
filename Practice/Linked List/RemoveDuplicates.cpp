void removeDuplicates()
{
    Node *p = head;
    Node *q = NULL;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        if (q->data == p->data)
        {
            q->next = p->next;
            delete p;
            p = q->next;
        }
    }
}