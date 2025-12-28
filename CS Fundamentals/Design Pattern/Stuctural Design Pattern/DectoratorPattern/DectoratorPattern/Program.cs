using System;

public interface ICoffee
{
    string GetDescription();
    double GetCost();
}

public class SimpleCoffe : ICoffee{
    public string GetDescription()
    {
        return "Simple Coffee";
    }

    public double GetCost()
    {
        return 100.0;
    }
}

public abstract class CoffeeDectorator : ICoffee
{
    public ICoffee _dectoratedCoffee;

    public CoffeeDectorator(ICoffee coffee)
    {
        _dectoratedCoffee = coffee;
    }
    
    public virtual string GetDescription()
    {
        return _dectoratedCoffee.GetDescription();
    }

    public virtual double GetCost()
    {
        return _dectoratedCoffee.GetCost();
    }
}


public class MilkDectorator : CoffeeDectorator
{
    public MilkDectorator(ICoffee coffee) : base(coffee)
    {
    }

    public override string GetDescription()
    {
        return _dectoratedCoffee.GetDescription() + " Milk";
    }

    public override double GetCost()
    {
        return _dectoratedCoffee.GetCost() + 100;
    }
}

public class SugarDectorator : CoffeeDectorator
{
    public SugarDectorator(ICoffee coffee) : base(coffee)
    {
    }

    public override string GetDescription()
    {
        return _dectoratedCoffee.GetDescription() + " Sugar";
    }

    public override double GetCost()
    {
        return _dectoratedCoffee.GetCost() + 50;
    }
}
public class HorilicsDectorator : CoffeeDectorator
{
    public HorilicsDectorator(ICoffee coffee) : base(coffee)
    {
    }

    public override string GetDescription()
    {
        return _dectoratedCoffee.GetDescription() + " Horlics";
    }

    public override double GetCost()
    {
        return _dectoratedCoffee.GetCost() + 150;
    }
}
class Program
{
    static void Main(string[] args)
    {
        ICoffee coffee = new SimpleCoffe();
        Console.WriteLine($"{coffee.GetDescription()} - {coffee.GetCost()}");
        
        coffee = new MilkDectorator(coffee);
        Console.WriteLine($"{coffee.GetDescription()} - {coffee.GetCost()}");
        coffee = new HorilicsDectorator(coffee);
        Console.WriteLine($"{coffee.GetDescription()} - {coffee.GetCost()}");
        //coffee = new SugarDectorator(coffee);
        //Console.WriteLine($"{coffee.GetDescription()} - {coffee.GetCost()}");
        
        ICoffee coffee1 = new SimpleCoffe();
        coffee1 = new MilkDectorator(coffee1);
        Console.WriteLine($"{coffee1.GetDescription()} - {coffee1.GetCost()}");
        coffee1 = new SugarDectorator(coffee1);
        Console.WriteLine($"{coffee1.GetDescription()} - {coffee1.GetCost()}");
    }
}