
public interface IObserver
{
    void Update(float price);
}

public interface ISubject
{
    void RegisterObserver(IObserver observer); // Add
    void UnregisterObserver(IObserver observer); // Remove
    void NotifyObservers(); // Notify
}

public class StockMarket : ISubject
{
    private List<IObserver> observers = new List<IObserver>();
    private float stockPrice;

    public void SetStockPrice(float price)
    {
        stockPrice = price;
        NotifyObservers();
    }
    public void RegisterObserver(IObserver observer)
    {
        observers.Add(observer);
    }

    public void UnregisterObserver(IObserver observer)
    {
        observers.Remove(observer);
    }

    public void NotifyObservers()
    {
        foreach (var observer in observers)
        {
            observer.Update(stockPrice);
        }
    }
}

public class Investor : IObserver
{
    public string name;

    public Investor(string name)
    {
        this.name = name;
    }
    public void Update(float price)
    {
        Console.WriteLine($"{name} notifying price of {price}");
    }
}

public class Program
{
    public static void Main()
    {
        StockMarket stockMarket = new StockMarket();
        IObserver investor1 = new Investor("Investor1");
        IObserver investor2 = new Investor("Investor2");
        IObserver investor3 = new Investor("Investor3");
        
        stockMarket.RegisterObserver(investor1);
        stockMarket.RegisterObserver(investor2);
        stockMarket.RegisterObserver(investor3);
        
        stockMarket.SetStockPrice(120.50f);
        stockMarket.SetStockPrice(200.50f);
        
        stockMarket.UnregisterObserver(investor2);
        
        stockMarket.SetStockPrice(150.50f);
        stockMarket.RegisterObserver(investor2);
        stockMarket.SetStockPrice(180.50f);
        
    }
}