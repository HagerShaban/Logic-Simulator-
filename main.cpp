/*
 * main.cpp
 * Created on: Sep 26, 2022
 * Author: Hager
 */

#include <iostream>
#include "string"
using namespace std;

/*
  class specifications
Default and non-default Constructor.
Provide setters and getters.
Overload the operator ostream << to print the node information.
Create methods called AND() / OR() / XOR() to perform the logical operation between two nodes objects.
Add any needed functions according to your design.
 */
enum Gates
{
    AND,OR,NAND,NOR,XOR,XNOR,NOT
};

class Node {
private:
    int status;
    char name;

public:
    // non default constructor
    Node();
    // non default constructor
    Node(int m_status,char m_name) ;
    //sets
    void set_name(char m2_name);
    void set_status(int m2_status);
    //gets
    char get_name();
    int  get_status();

    //operator overloading to print node information
    friend ostream& operator<<(ostream& out, const Node & node)
    {
        out <<node.name  << ": "<<node.status<< endl;
        return out;
    }

    //methods to perform operation between 2 nodes
    int AND(int firstN,int secondN);
    int XOR(int firstN,int secondN);
    int OR(int firstN,int secondN);
};

/*
 Class Gate should support the following methods:
Default and non-default Constructors.
Provide getters and setters for its nodes.
Implement the gate types AND / OR / NAND / NOR / XOR / XNOR / NOT.
function simulateGate() returns the logic value of the gate according to its type.
 */
class Gate {
protected:
    Node node1;  //input1
    Node node2;  //input2
    Node node3;  //output
    Gates g_type;  //logic gate type

public:
    // default constructor
    Gate();
    // non default constructor
    Gate(Node f_node, Node s_node,Node th_node);

    //sets name &status&type
    void setname_N1(char Name );
    void setname_N2(char Name );
    void setname_N3(char Name );

    void setstatus_N1(int Stat );
    void setstatus_N2(int Stat );
    void setstatus_N3(int Stat );
    void setGateType(Gates type);

    /*void set_input1(char Name,int Stat);
    void set_input2(char Name,int Stat);
    void set_input3(char Name,int Stat);*/


    //gets name &status&type
    char Getname_N1();
    char Getname_N2();
    char Getname_N3();

    int Getstatus_N1();
    int Getstatus_N2();
    int Getstatus_N3();
    Gates Get_Type( );

    /* Node get_input1();
    Node get_input2();
    Node get_input3();*/


    //function simulateGate() returns the logic value of the gate according to its type.
    void simulateGate(int LOGIC);

};

/*
array of pointers to Gate and array of pointers to Node.
Method postGate() accepts a pointer to a created gate to insert it into the array.
Method postNode() accepts a pointer to a created node to insert it into the array.
Method FindNode() accepts a string node's name to find it in the container and return its address.
Method startSimulate() start the simulation for each gate by looping over the gates container
 */

class Simulator {
public:
    // default constructor
    Simulator();
    static Gate G_array[100];
    static Node N_array[100];

    static int gate_nums;
    static int node_nums;
    static int TypeNum;
    static int Output;



    static void postGate(const Gate & VAR );
    static void postNode(const Node & VAR);
    static int  FindNode( char name);

    static void startSimulate();

    static Gates FindType(string line);
    static void Print();
    static void Set_Nodes(char Name,int stat);

};


/*
GateGenerator" class should have the following specifications:
Function parseInput() reads the inputs and parses each keyword ("SIM"/"OUT",..) to the appropriate logic.
Function createNode() creates a node and return its address.
Function createGate() creates a (AND,OR,...) gates according to the input and return its address, it is advisable to use a factory function to have better practice on polymorphic objects.
Add any needed functions as your design says so!.
 */
class GateGenerator
{
    string InputStrings[100];
public:
    GateGenerator();
    void  parseInput();
    void  createNode(Node node);
    void  createGate(string Line );

};


/*functions of each class*/
// 1.Node class

Node::Node()
{
    /*    //initialization
    status=0;
    name=0;*/
    this->status = 0;
    this->name = 0;
}

Node::Node(int m_status, char m_name):status(m_status),name(m_name)
{
    this->status = status;
    this->name = name;
}
int Node:: OR(int firstN,int secondN)
{
    if (firstN == 0 && secondN ==0)
        return 0;
    else
        return 1;
}

int Node::AND(int firstN,int secondN)
{
    if (firstN == 1 && secondN ==1)
        return 1;
    else
        return 0;
}
int Node::XOR(int firstN,int secondN)
{
    if (firstN == secondN)
        return 0;
    else
        return 1;
}

void Node::set_name(char m_name)
{
    name = m_name;
}

void Node::set_status(int m_status) {
    status = m_status;
}

char Node::get_name() {
    return name;
}


int Node::get_status() {
    return status;
}



// 2.gate class
Gate ::Gate()
{

}

Gate ::Gate(Node f_node, Node s_node,Node th_node):node1(f_node),node2(s_node),node3(th_node)
{

}

//set names
void Gate :: setname_N1(char Name )
{
    node1.set_name(Name);
}
void Gate ::setname_N2(char Name )
{
    node2.set_name(Name);
}
void Gate ::setname_N3(char Name )
{
    node3.set_name(Name);
}

//set status
void Gate ::setstatus_N1(int Stat )
{
    node1.set_status( Stat );
}
void Gate ::setstatus_N2(int Stat )
{
    node2.set_status( Stat );
}
void Gate ::setstatus_N3(int Stat)
{
    node3.set_status( Stat );
}

//set gate type
void Gate :: setGateType(Gates type)
{
    g_type= type;
}

//get names
char Gate:: Getname_N1()
{
    return node1.get_name();
}
char Gate:: Getname_N2()
{
    return node2.get_name();
}
char Gate::Getname_N3()
{
    return node3.get_name();

}

//get status
int Gate::Getstatus_N1()
{
    return node1.get_status();
}
int Gate::Getstatus_N2()
{
    return node2.get_status();
}
int Gate::Getstatus_N3()
{
    return node3.get_status();
}

//get gate type
Gates Gate :: Get_Type( )
{
    return g_type;
}

// how logic gates will simulate
void Gate :: simulateGate(int LOGIC)
{

    switch (g_type)
    {
    case AND : {
        if(node1.get_status() == 1 && node2.get_status() ==1)
        {
            node3.set_status(1);
            Simulator::Set_Nodes( node3.get_name(),1);

        }
        else
        {
            node3.set_status(0);
            Simulator::Set_Nodes( node3.get_name(),0);
        }
        break;
    }
    case OR : {

        if (node1.get_status() == 0 && node2.get_status() ==0)
        {
            node3.set_status(0);
            Simulator::Set_Nodes( node3.get_name(),0);

        }
        else
        {
            node3.set_status(1);
            Simulator::Set_Nodes( node3.get_name(),1);
        }

        break;
    }

    case NOT : {

        if (node1.get_status() == 0 )
        {
            node3.set_status(1);
            Simulator::Set_Nodes( node3.get_name(),1);
        }
        else
        {
            node3.set_status(0);
            Simulator::Set_Nodes( node3.get_name(),0);
        }
        break;
    }

    case XOR :  {

        if (node1.get_status()== node2.get_status())
        {
            node3.set_status(0);
            Simulator::Set_Nodes( node3.get_name(),0);

        }
        else
        {
            node3.set_status(1);
            Simulator::Set_Nodes( node3.get_name(),1);
        }
        break;
    }
    case XNOR : {

        if (node1.get_status()== node2.get_status())
        {
            node3.set_status(1);
            Simulator::Set_Nodes( node3.get_name(),1);

        }
        else
        {
            node3.set_status(0);
            Simulator::Set_Nodes( node3.get_name(),0);
        }
        break;
    }

    case NAND : {

        if (node1.get_status() == 0 || node2.get_status() == 0)
        {
            node3.set_status(1);
            Simulator::Set_Nodes( node3.get_name(),1);

        }
        else
        {
            node3.set_status(0);
            Simulator::Set_Nodes( node3.get_name(),0);
        }
        break;
    }
    case NOR : {
        if (node1.get_status() == 1 || node2.get_status() == 1)
        {
            node3.set_status(0);
            Simulator::Set_Nodes( node3.get_name(),0);

        }
        else
        {
            node3.set_status(1);
            Simulator::Set_Nodes( node3.get_name(),1);
        }
        break;
    }
    }
}

/*
 * class Simulator {
public:
    Simulator(); // default constructor
    static Gate G_array[500];
    static Node N_array[500];
    static void postGate(const Gate & obj );
    static void postNode(const Node & obj);
    static int  FindNode( char name);
    static void startSimulate();
    static string FindType(string line);
    static void Print();
    static void SetAllNodes(char Name,int stat);

};
 */

//simulator functions

int Simulator:: TypeNum=0;
int Simulator:: gate_nums=0;
int Simulator:: node_nums=0;
int Simulator:: Output=-1;
Gate Simulator::G_array[]={ Gate(Node(0,'\0'),Node(0,'\0'),Node(0,'\0')) };
Node Simulator::N_array[]={Node(0,'\0')};

Simulator::Simulator()
{

}
void Simulator:: startSimulate()
{
    for (int i = 0; i < gate_nums; ++i)
    {
        G_array[i].simulateGate(i);
    }

    Simulator::Print();
}

void Simulator:: postNode(const Node & VAR)
{
    N_array[node_nums]=VAR;
    node_nums++;
}

void Simulator:: postGate(const Gate & VAR )
{
    G_array[gate_nums]=VAR;
    gate_nums++;
}

int Simulator:: FindNode( char name)
{
    signed int i;
    for(i=0;i<node_nums;i++)
    {
        if(N_array[i].get_name()==name)
        {
            return i;
        }
    }

    return -1;
}


Gates Simulator::FindType(string line)
{
    switch(line[0]){

    case 'X' : {
        if(line[1]=='N')
        {
            TypeNum=4;
            return XNOR;
        }
        else
        {   TypeNum=3;
        return XOR;
        }
        break;

    }

    case 'O': {

        TypeNum=2;
        return OR;

        break;
    }

    case 'A': {

        TypeNum=3;
        return AND;

        break;

    }
    case 'N': {
        if(line[1]=='A')
        {
            TypeNum=4;
            return NAND;
        }
        else if(line[2]=='R')
        {
            TypeNum=3;
            return NOR;
        }
        else
        {
            TypeNum=3;
            return NOT;
        }


        break;
    }

    }
    return OR;
}
void Simulator::Print()
{
    cout<<N_array[Output];
    for (int i = 0; i <node_nums ; ++i)
    {
        cout<<N_array[i];
    }
}

void Simulator:: Set_Nodes(char Name,int stat)
{
    for (int i = 0; i <gate_nums ; i++)
    {
        if(Name==G_array[i].Getname_N1())
        {
            G_array[i].setstatus_N1(stat);
        }
        if(Name==G_array[i].Getname_N2())
        {
            G_array[i].setstatus_N2(stat);
        }
        if(Name==G_array[i].Getname_N3())
        {
            G_array[i].setstatus_N3(stat);
        }

    }

    for (int i = 0; i < node_nums; i++)
    {
        if(Name==N_array[i].get_name())
        {
            N_array[i].set_status(stat);
        }
    }
}

//generator functions

Gate Gate_VAR;
char Right_Char;
GateGenerator::GateGenerator()
{

}
void GateGenerator :: createNode(Node node)
{
    Simulator::postNode(node);
}
void  GateGenerator::createGate(string Line )
{
    int NOT_State=0;
    Gate_VAR.setGateType(Simulator::FindType(Line));

    if(Simulator::FindType(Line) == NOT)
    {
        NOT_State=1;
    }

    Right_Char=Line[Simulator::TypeNum+1];

    if(Simulator::FindNode(Right_Char)== -1)
    {
        Node para(0,Right_Char);
        Gate_VAR.setname_N1(Right_Char);
        createNode(para);
    }
    else
    {
        Gate_VAR.setname_N1(Right_Char);
    }


    Right_Char=Line[Simulator::TypeNum+3];

    if((NOT_State==0)&&(Simulator::FindNode(Right_Char)== -1))
    {
        Node para(0,Right_Char);
        Gate_VAR.setname_N2(Right_Char);
        createNode(para);
    }
    else if(NOT_State==0)
    {
        Gate_VAR.setname_N2(Right_Char);
    }
    if(NOT_State==0)
    {
        Right_Char = Line[Simulator::TypeNum + 5];
    }
    if(Simulator::FindNode(Right_Char)== -1)
    {
        Node para(0,Right_Char);
        Gate_VAR.setname_N3(Right_Char);
        createNode(para);
    }
    else
    {
        Gate_VAR.setname_N3(Right_Char);
    }

    Simulator::postGate(Gate_VAR);
}


void GateGenerator::parseInput()
{
    int i;
    int status=0;
    for(i=0;status==0;i++)
    {
        getline (cin,InputStrings[i]);

        if(InputStrings[i][1]=='U')
        {
            status=1;
        }
    }

    i=0;

    while(InputStrings[i][1]!='U')
    {
        if(InputStrings[i][0]!='S')
        {
            createGate(InputStrings[i]);
        }
        else if(InputStrings[i][0]=='S')
        {
            if(InputStrings[i][1]=='E')
            {

                if(InputStrings[i][6]=='0')
                {
                    Simulator::Set_Nodes(InputStrings[i][4],0);
                }
                else
                {
                    Simulator::Set_Nodes(InputStrings[i][4],1);

                }

            }
            else
            {
                Simulator::Output=Simulator::FindNode(InputStrings[i+1][4]);
                Simulator::startSimulate();
            }
        }

        i++;
    }

}


int main() {
    GateGenerator x;
    x.parseInput();
    return 0;
}


