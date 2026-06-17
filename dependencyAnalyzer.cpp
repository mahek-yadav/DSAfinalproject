#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Supplier {
    int id;
    string name;
    Supplier* next;

    Supplier(int i, string n) {
        id = i;
        name = n;
        next = NULL;
    }
};

class SupplierList {
private:
    Supplier* head;

public:
    SupplierList() {
        head = NULL;
    }

    void addSupplier(int id, string name) {
        Supplier* newNode = new Supplier(id, name);

        if (head == NULL) {
            head = newNode;
            cout << "Supplier Added Successfully!\n";
            return;
        }

        Supplier* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        cout << "Supplier Added Successfully!\n";
    }

    void displaySuppliers() {
        if (head == NULL) {
            cout << "No Suppliers Found.\n";
            return;
        }

        Supplier* temp = head;
        cout << "\nSupplier List:\n";

        while (temp != NULL) {
            cout << "ID: " << temp->id
                 << " | Name: " << temp->name << endl;
            temp = temp->next;
        }
    }

    void updateSupplier(int id) {
        Supplier* temp = head;

        while (temp != NULL) {
            if (temp->id == id) {
                cout << "Enter New Supplier Name: ";
                cin.ignore();
                getline(cin, temp->name);
                cout << "Supplier Updated Successfully!\n";
                return;
            }
            temp = temp->next;
        }

        cout << "Supplier Not Found.\n";
    }

    void deleteSupplier(int id) {
        if (head == NULL) {
            cout << "List Empty.\n";
            return;
        }

        if (head->id == id) {
            Supplier* del = head;
            head = head->next;
            delete del;
            cout << "Supplier Deleted Successfully!\n";
            return;
        }

        Supplier* temp = head;

        while (temp->next != NULL && temp->next->id != id)
            temp = temp->next;

        if (temp->next == NULL) {
            cout << "Supplier Not Found.\n";
            return;
        }

        Supplier* del = temp->next;
        temp->next = temp->next->next;
        delete del;

        cout << "Supplier Deleted Successfully!\n";
    }

    vector<pair<int,string>> getSupplierVector() {
        vector<pair<int,string>> suppliers;

        Supplier* temp = head;

        while (temp != NULL) {
            suppliers.push_back({temp->id,temp->name});
            temp = temp->next;
        }

        return suppliers;
    }
};

class SupplyGraph {
private:
    int vertices;
    vector<vector<int>> adj;

public:
    SupplyGraph(int v = 20) {
        vertices = v;
        adj.resize(v);
    }

    void addDependency(int a, int b) {
        if(a >= vertices || b >= vertices){
            cout << "Node out of range.\n";
            return;
        }

        adj[a].push_back(b);
        cout << "Dependency Added Successfully!\n";
    }

    void displayGraph() {
        cout << "\nSupply Chain Network:\n";

        for (int i = 0; i < vertices; i++) {
            if (!adj[i].empty()) {
                cout << i << " -> ";
                for (int n : adj[i])
                    cout << n << " ";
                cout << endl;
            }
        }
    }

    void DFSUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor])
                DFSUtil(neighbor, visited);
        }
    }

    void criticalDependencyDFS(int start) {
        vector<bool> visited(vertices, false);

        cout << "\nCritical Dependency Chain:\n";
        DFSUtil(start, visited);
        cout << endl;
    }

    void alternativeSupplierBFS(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "\nAlternative Supplier Path:\n";

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            cout << current << " ";

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    void riskAnalysis() {
        cout << "\n===== RISK ANALYSIS REPORT =====\n";

        for (int i = 0; i < vertices; i++) {
            if (!adj[i].empty()) {
                cout << "Supplier Node " << i
                     << " has " << adj[i].size()
                     << " dependency(s). ";

                if (adj[i].size() >= 3)
                    cout << "[HIGH RISK]";
                else if (adj[i].size() == 2)
                    cout << "[MEDIUM RISK]";
                else
                    cout << "[LOW RISK]";

                cout << endl;
            }
        }
    }

    void procurementAnalytics() {
        cout << "\n===== PROCUREMENT ANALYTICS =====\n";

        int totalDependencies = 0;

        for (int i = 0; i < vertices; i++)
            totalDependencies += adj[i].size();

        cout << "Total Nodes: " << vertices << endl;
        cout << "Total Dependency Links: "
             << totalDependencies << endl;

        cout << "Average Dependencies per Node: "
             << (double)totalDependencies / vertices
             << endl;
    }

    void generateAlerts() {
        cout << "\n===== OPERATIONAL ALERTS =====\n";

        bool found = false;

        for (int i = 0; i < vertices; i++) {
            if (adj[i].size() >= 3) {
                found = true;

                cout << "ALERT: Supplier Node "
                     << i
                     << " has HIGH dependency risk.\n";
            }
        }

        if (!found)
            cout << "No operational alerts.\n";
    }
};

void binarySearchSupplier(vector<pair<int,string>> suppliers, int target) {

    sort(suppliers.begin(), suppliers.end());

    int low = 0;
    int high = suppliers.size() - 1;

    while (low <= high) {

        int mid = (low + high) / 2;

        if (suppliers[mid].first == target) {
            cout << "\nSupplier Found!\n";
            cout << "ID: " << suppliers[mid].first
                 << "\nName: " << suppliers[mid].second
                 << endl;
            return;
        }

        else if (suppliers[mid].first < target)
            low = mid + 1;

        else
            high = mid - 1;
    }

    cout << "Supplier Not Found.\n";
}

int main() {

    SupplierList supplierList;
    SupplyGraph graph(20);

    int choice;

    do {
        cout << "\n==============================";
        cout << "\nSMART MANUFACTURING ANALYZER";
        cout << "\n==============================\n";

        cout << "1. Register Supplier\n";
        cout << "2. Display Suppliers\n";
        cout << "3. Update Supplier\n";
        cout << "4. Delete Supplier\n";
        cout << "5. Add Dependency\n";
        cout << "6. Display Network\n";
        cout << "7. Critical Dependency Analysis (DFS)\n";
        cout << "8. Alternative Supplier Discovery (BFS)\n";
        cout << "9. Search Supplier (Binary Search)\n";
        cout << "10. Risk Analysis Report\n";
        cout << "11. Procurement Analytics\n";
        cout << "12. Operational Alerts\n";
        cout << "13. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {

            case 1: {
                int id;
                string name;

                cout << "Enter Supplier ID: ";
                cin >> id;

                cin.ignore();

                cout << "Enter Supplier Name: ";
                getline(cin, name);

                supplierList.addSupplier(id, name);
                break;
            }

            case 2:
                supplierList.displaySuppliers();
                break;

            case 3: {
                int id;
                cout << "Enter Supplier ID to Update: ";
                cin >> id;
                supplierList.updateSupplier(id);
                break;
            }

            case 4: {
                int id;
                cout << "Enter Supplier ID to Delete: ";
                cin >> id;
                supplierList.deleteSupplier(id);
                break;
            }

            case 5: {
                int a, b;

                cout << "Enter Supplier Node: ";
                cin >> a;

                cout << "Depends On Node: ";
                cin >> b;

                graph.addDependency(a, b);
                break;
            }

            case 6:
                graph.displayGraph();
                break;

            case 7: {
                int start;

                cout << "Enter Starting Node: ";
                cin >> start;

                graph.criticalDependencyDFS(start);
                break;
            }

            case 8: {
                int start;

                cout << "Enter Starting Node: ";
                cin >> start;

                graph.alternativeSupplierBFS(start);
                break;
            }

            case 9: {
                int id;

                cout << "Enter Supplier ID to Search: ";
                cin >> id;

                binarySearchSupplier(
                    supplierList.getSupplierVector(),
                    id
                );
                break;
            }

            case 10:
                graph.riskAnalysis();
                break;

            case 11:
                graph.procurementAnalytics();
                break;

            case 12:
                graph.generateAlerts();
                break;

            case 13:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid Choice.\n";
        }

    } while(choice != 13);

    return 0;
}
