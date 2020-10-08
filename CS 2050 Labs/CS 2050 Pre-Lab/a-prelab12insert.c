int insertPQ(float temperature, float priority, PQueue pq) {

    //Alias to the WeatherList *
    List *list = pq.list;

    //Null check weather list info
    if (list == NULL) {
        return -1;
    }

    //Create a new Weather Struct
    Node * wNode = createNode(priority, temperature);

    //If valid
    if (wNode) {
        //Increment the number of items
        list->size++;

        //If the queue is empty
        if (list->head == NULL && list->tail == NULL) {
            //Set the head and tail to be the new weather node
            list->head = wNode;
            list->tail = wNode;

            //success
            return 1;

        }


    //If list is not empty, search through the entire queue until the lower priority is found and insert before

    if (list->head->priority < wNode->priority){ //If the head priority is less than the wNode priority
            //wNode becomes the new head
            //insert before old head

            //Point to old head
            wNode->next = list->head;

            //point old head previous to the new node
            list->head->previous = wNode;

            //new node becomes head
            list->head = wNode;
        }
        else {
            //Iterate through rest
            Node * p = list->head;

            //Find the pointer with the next priority smaller than the new priority
            while (p->next != NULL && p->next->priority > wNode->priority) {
                p = p->next;
            }

            //Insert in between p (larger priority) and p->next (smaller priority)

            //Check if the next pointer is not null
            if (p->next != NULL) {
                //Tell next pointer to point backwards to weather node
                p->next->previous = wNode;
            }else {
                //If it is null, mark the wNode as the tail
                list->tail = wNode;
            }

            //Insert wNode between p and p->next

            //Next after weather node is p->next
            wNode->next = p->next;

            //weather node previous points back to p
            wNode->previous = p;

            //p->next now points to new weather node
            p->next = wNode;


        }

        //Success return 1
        return 1;

    }else {

        //Fail return -1
        return -1;
    }

}
