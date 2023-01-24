#include <iostream>
using namespace std;

class node
{
public:
    float coefficient;
    int exponent;
    node *next;
};

class LinkedList
{
private:
    node *head;
public:
    LinkedList()
    {
        head = NULL;
    }
    node *createNewNode(float coeff, int exp)
    {
        node *newNode = new node;
        if (newNode == NULL)
            throw("Couldn't allocate space for new node.");
        newNode->coefficient = coeff;
        newNode->exponent = exp;
        newNode->next = NULL;
        return newNode;
    }
    void insert(float coeff, int exp)
    {
        node *newNode = createNewNode(coeff, exp);
        if (head == NULL)
            head = newNode;
        else
        {
            node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << "Inserted " << coeff << " with exponent " << exp << "." << endl;
    }
    void getPolynomial()
    {
        int numberOfTerms, exponent;
        float coefficient;
        cout << "Number of terms: ";
        cin >> numberOfTerms;
        for (int i = 0; i < numberOfTerms; i++)
        {
            cout << "Enter coefficient and exponent[separated by a space](Example: 2 5): ";
            cin >> coefficient >> exponent;
            insert(coefficient, exponent);
        }
    }
    void display()
    {
        node *temp = head;
        cout << "Coefficient     Exponent" << endl;
        while (temp != NULL)
        {
            cout << temp->coefficient << "\t\t" << temp->exponent << endl;
            temp = temp->next;
        }
    }
    friend void addPolynomials(LinkedList *p, LinkedList *q, LinkedList *r);
};

void addPolynomials(LinkedList *p, LinkedList *q, LinkedList *r)
{
    node *ptrp = p->head, *ptrq = q->head;
    while (ptrp && ptrq) // loop will terminate when one of them in NULL
    {
        if (ptrp->exponent > ptrq->exponent)
        {
            r->insert(ptrp->coefficient, ptrp->exponent);
            ptrp = ptrp->next;
        }
        else if (ptrp->exponent < ptrq->exponent)
        {
            r->insert(ptrq->coefficient, ptrq->exponent);
            ptrq = ptrq->next;
        }
        else
        {
            r->insert(ptrp->coefficient + ptrq->coefficient, ptrp->exponent);
            ptrp = ptrp->next;
            ptrq = ptrq->next;
        }
    }

    while (ptrp || ptrq) // loop will only terminate when both are NULL, one of them is already NULL so the other has to be NULL
    {
        if (ptrp) // ptrp is not NULL i.e. p has terms remaining
        {
            r->insert(ptrp->coefficient, ptrp->exponent);
            ptrp = ptrp->next;
        }
        else // ptrp is NULL i.e q has terms remaining
        {
            r->insert(ptrq->coefficient, ptrq->exponent);
            ptrq = ptrq->next;
        }
    }
}

int main()
{
    LinkedList p, q, r;
    cout << "Polynomial p" << endl;
    p.getPolynomial();
    cout << "Polynomial q" << endl;
    q.getPolynomial();
    addPolynomials(&p, &q, &r);

    cout << "Polynomial p" << endl;
    p.display();
    cout << "Polynomial q" << endl;
    q.display();
    cout << "Polynomial r=p+q" << endl;
    r.display();
    return 0;
}