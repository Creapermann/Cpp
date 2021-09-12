
/*
TASK:
Merge two sorted linked lists and return it as a sorted list. 
The list should be made by splicing together the nodes of the first two lists.
*/


struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};



class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (l1 == nullptr && l2 == nullptr)
            return {};
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;

        ListNode* start{ nullptr };
        ListNode** curr{ &start };


        if (l1->val <= l2->val)
        {
            (*curr) = l1;
            l1 = l1->next;
        }
        else
        {
            (*curr) = l2;
            l2 = l2->next;
        }

        while (true)
        {
            if (l1 != nullptr && l2 != nullptr)
            {
                if (l1->val <= l2->val)
                {
                    (*curr)->next = l1;
                    l1 = l1->next;
                }
                else
                {
                    (*curr)->next = l2;
                    l2 = l2->next;
                }

                curr = &(*curr)->next;
            }
            else
            {
                if (l1 == nullptr && l2 != nullptr)
                {
                    (*curr)->next = l2;
                }
                if (l1 != nullptr && l2 == nullptr)
                {
                    (*curr)->next = l1;
                }

                break;
            }
        }

        return start;
    }
};



int main()
{
    ListNode* l1 = new ListNode;
    ListNode* l2 = new ListNode;
    ListNode* l3 = new ListNode;

    l1->val = 1;
    l2->val = 2;
    l3->val = 4;

    l1->next = l2;
    l2->next = l3;
    l3->next = nullptr;

    ListNode* m1 = new ListNode;
    ListNode* m2 = new ListNode;
    ListNode* m3 = new ListNode;

    m1->val = 1;
    m2->val = 3;
    m3->val = 4;

    m1->next = m2;
    m2->next = m3;
    m3->next = nullptr;

    Solution sol;
    sol.mergeTwoLists(l1, m1);
}