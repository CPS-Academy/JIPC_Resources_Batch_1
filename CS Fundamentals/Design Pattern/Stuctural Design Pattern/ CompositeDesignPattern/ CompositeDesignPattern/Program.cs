
public abstract class OrgranationUnit
{
    protected string _name;

    public OrgranationUnit(string name)
    {
        _name = name;
    }

    public abstract int GetBudget();
    public virtual void AddUnit(OrgranationUnit unit){}
    public virtual void RemoveUnit(OrgranationUnit unit){}
}

public class Employee : OrgranationUnit
{
    private int _salary;
    public Employee(string name,int salary) : base(name)
    {
        _salary = salary;
    }

    public override int GetBudget()
    {
        Console.WriteLine("Employee " + _name + " is " + _salary);
        return _salary;
    }
}

public class Department : OrgranationUnit
{
    private List<OrgranationUnit> _units = new List<OrgranationUnit>();

    public Department(string name) : base(name)
    {
        
    }

    public override void AddUnit(OrgranationUnit unit)
    {
        _units.Add(unit);
    }

    public override int GetBudget()
    {
        Console.WriteLine("Department " + _name + " is " + _units.Count);
        int totalBudget = 0;
        foreach (var unit in _units)
        {
            totalBudget += unit.GetBudget();
        }
        Console.WriteLine("Total budget: " + totalBudget);
        return totalBudget;
    }
}

public class Program
{
    public static void Main()
    {
        var john = new Employee("John", 25000);
        var bob = new Employee("Bob", 30000);
        var alice = new Employee("Alice", 40000);
        var subhashis = new Employee("subhashis", 20000);
        
        var devTeam = new Department("DevTeam");
        var qaTeam = new Department("QaTeam");
        
        var company = new Department("Company");
        
        devTeam.AddUnit(john);
        devTeam.AddUnit(bob);
        
        qaTeam.AddUnit(alice);
        
        company.AddUnit(devTeam);
        company.AddUnit(qaTeam);
        
        company.AddUnit(subhashis);
        int finalBudget = company.GetBudget();
        Console.WriteLine("Total budget: " + finalBudget);
    }
}

//Company 
  ///  Subhahis = Dev = QATeam 
     //        john,bob   alice

// Employee Create
// Dept create
// dept - employee add
// company - dept 
// total budget calculate