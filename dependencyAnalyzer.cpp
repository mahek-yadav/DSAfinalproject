#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

// ===============================
// LINKED LIST FOR SUPPLIER STORAGE
// ===============================

struct Supplier
{
    int id;
    string name;
    Supplier* next;

    Supplier(int i, string n)
    {
        id = i;
        name = n;
        next = NULL;
    }
};

class SupplierList
{
private:
    Supplier* head;

public:
    SupplierList()
    {
        head = NULL;
    }

    void addSupplier(int id, string name)
    {
        Supplier* newNode = new Supplier(id, name);

        if(head == NULL)
        {
            head = newNode;
            return;
        }

        Supplier* temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;

        cout << "Supplier Added Successfully!\n";
    }

    void displaySuppliers()
    {
        if(head == NULL)
        {
            cout << "No Suppliers Found.\n";
            return;
        }

        Supplier* temp = head;

        cout << "\nSupplier List:\n";

        while(temp != NULL)
        {
            cout << "ID: " << temp->id
                 << " Name: " << temp->name << endl;

            temp = temp->next;
        }
    }

    vector<pair<int,string>> getSupplierVector()
    {
        vector<pair<int,string>> suppliers;

        Supplier* temp = head;

        while(temp != NULL)
        {
            suppliers.push_back({temp->id,temp->name});
            temp = temp->next;
        }

        return suppliers;
    }
};

// ===============================
// GRAPH FOR SUPPLY CHAIN
// ===============================

class SupplyGraph
{
private:
    int vertices;
    vector<vector<int>> adj;

public:
    SupplyGraph(int v = 20)
    {
        vertices = v;
        adj.resize(v);
    }

    void addDependency(int supplierA, int supplierB)
    {
        adj[supplierA].push_back(supplierB);

        cout << "Dependency Added Successfully!\n";
    }

    // DFS
    void DFSUtil(int node, vector<bool>& visited)
    {
        visited[node] = true;

        cout << node << " ";

        for(int neighbor : adj[node])
        {
            if(!visited[neighbor])
                DFSUtil(neighbor, visited);
        }
    }

    void criticalDependencyDFS(int start)
    {
        vector<bool> visited(vertices,false);

        cout << "\nCritical Dependency Chain:\n";

        DFSUtil(start,visited);

        cout << endl;
    }

    // BFS
    void alternativeSupplierBFS(int start)
    {
        vector<bool> visited(vertices,false);

        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "\nAlternative Supplier Path:\n";

        while(!q.empty())
        {
            int current = q.front();
            q.pop();

            cout << current << " ";

            for(int neighbor : adj[current])
            {
                if(!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        cout << endl;
    }

    void displayGraph()
    {
        cout << "\nSupply Chain Network:\n";

        for(int i=0;i<vertices;i++)
        {
            if(adj[i].size()>0)
            {
                cout << i << " -> ";

                for(int neighbor : adj[i])
                    cout << neighbor << " ";

                cout << endl;
            }
        }
    }
};

// ===============================
// BINARY SEARCH
// ===============================

void binarySearchSupplier(vector<pair<int,string>> suppliers,int target)
{
    sort(suppliers.begin(), suppliers.end());

    int low = 0;
    int high = suppliers.size()-1;

    while(low <= high)
    {
        int mid = (low + high)/2;

        if(suppliers[mid].first == target)
        {
            cout << "\nSupplier Found!\n";
            cout << "ID: " << suppliers[mid].first
                 << "\nName: " << suppliers[mid].second
                 << endl;
            return;
        }

        else if(suppliers[mid].first < target)
            low = mid + 1;

        else
            high = mid - 1;
    }

    cout << "\nSupplier Not Found.\n";
}

// ===============================
// MAIN PROGRAM
// ===============================

int main()
{
    SupplierList supplierList;

    SupplyGraph graph(20);

    int choice;

    do
    {
        cout << "\n==============================";
        cout << "\nSMART MANUFACTURING ANALYZER";
        cout << "\n==============================";

        cout << "\n1. Register Supplier";
        cout << "\n2. Display Suppliers";
        cout << "\n3. Add Dependency";
        cout << "\n4. Display Network";
        cout << "\n5. Critical Dependency Analysis (DFS)";
        cout << "\n6. Alternative Supplier Discovery (BFS)";
        cout << "\n7. Search Supplier (Binary Search)";
        cout << "\n8. Exit";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                int id;
                string name;

                cout << "Enter Supplier ID: ";
                cin >> id;

                cin.ignore();

                cout << "Enter Supplier Name: ";
                getline(cin,name);

                supplierList.addSupplier(id,name);

                break;
            }

            case 2:
            {
                supplierList.displaySuppliers();
                break;
            }

            case 3:
            {
                int a,b;

                cout << "Enter Supplier Node: ";
                cin >> a;

                cout << "Depends On Node: ";
                cin >> b;

                graph.addDependency(a,b);

                break;
            }

            case 4:
            {
                graph.displayGraph();
                break;
            }

            case 5:
            {
                int start;

                cout << "Enter Starting Supplier Node: ";
                cin >> start;

                graph.criticalDependencyDFS(start);

                break;
            }

            case 6:
            {
                int start;

                cout << "Enter Supplier Node: ";
                cin >> start;

                graph.alternativeSupplierBFS(start);

                break;
            }

            case 7:
            {
                int target;

                cout << "Enter Supplier ID to Search: ";
                cin >> target;

                binarySearchSupplier(
                    supplierList.getSupplierVector(),
                    target
                );

                break;
            }

            case 8:
            {
                cout << "\nExiting...\n";
                break;
            }

            default:
            {
                cout << "\nInvalid Choice.\n";
            }
        }

    } while(choice != 8);

    return 0;
}