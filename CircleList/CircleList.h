#pragma once

struct NODE {
    string data;
    NODE* next;
};

struct CIRCLELIST {
    NODE* last;

    void init() {
        last = nullptr;
    }

    bool isEmpty() {
        return last == nullptr;
    }

    bool insert(string x, int k) {
        NODE* newNode = new NODE();
        // add to an empty list
        if (k == 1 && this->isEmpty()) {
            newNode->data = x;
            last = newNode;
            last->next = last;
            return 1;
        }
        // push front
        if (k == 1) {
            newNode->data = x;
            newNode->next = last->next;
            last->next = newNode;
            return 1;
        }

        if (k < 1 || k > this->size())
            return 0;

        NODE* tmp = last->next;
        for (int i = 1; i < k - 1; i++)
            tmp = tmp->next;
        newNode->data = x;
        newNode->next = tmp->next;
        tmp->next = newNode;
        return 1;
    }

    bool deleteNode(int k) {
        if (k < 1 || k > this->size())
            return 0;

        // pop front
        if (k == 1) {
            NODE* tmp = last->next; // tmp = head node
            // if the list contains only one node
            if (last->next->next == last->next)
                last = nullptr; // list becomes empty
            else
                last->next = last->next->next; // head node = head node->next
            delete(tmp);
            return 1;
        }

        // pop back
        if (k == this->size()) {
            NODE* tmp = last->next;
            // traversal to near last node
            while (tmp->next->next != last->next)
                tmp = tmp->next;
            NODE* lastNode = tmp->next;
            // let the next part của near last node points to head node
            tmp->next = last->next;
            last->data = tmp->data;
            // near last node becomes last node
            last = tmp;
            delete(lastNode);
            return 1;
        }

        NODE* tmp = last->next;
        for (int i = 1; i < k - 1; i++)
            tmp = tmp->next;
        NODE* kth = tmp->next;
        tmp->next = kth->next;
        delete(kth);
        return 1;
    }

    string dataOfNode(int k) {
        NODE* tmp = last->next;
        int cnt = 0;
        do {
            ++cnt;
            if (cnt == k)
                return tmp->data;
            tmp = tmp->next;
        } while (tmp != last->next);
    }

    int size() {
        if (this->isEmpty())
            return 0;
        NODE* tmp = last->next;
        int cnt = 0;
        do {
            cnt++;
            tmp = tmp->next;
        } while (tmp != last->next);
        return cnt;
    }
};


