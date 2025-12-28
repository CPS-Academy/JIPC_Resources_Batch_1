interface IPaymentStrategy
{
    void Pay(double amount);
}

class CreditCardPayment : IPaymentStrategy
{
    public void Pay(double amount)
    {
        Console.WriteLine($"Paid {amount} using CreditCard");
    }
}

class PaypalPayment : IPaymentStrategy
{
    public void Pay(double amount)
    {
        Console.WriteLine($"Paid {amount} using PayPal");
    }
}

class CashPayment : IPaymentStrategy
{
    public void Pay(double amount)
    {
        Console.WriteLine($"Paid {amount} using Cash");
    }
}

class ShoppingCart
{
    private IPaymentStrategy _paymentStrategy;

    public void SetPaymentStrategy(IPaymentStrategy paymentStrategy)
    {
        _paymentStrategy = paymentStrategy;
    }

    public void Checkout(double amount)
    {
        if (_paymentStrategy == null)
        {
            Console.WriteLine("Please Select the Payment Method");
        }
        else
        {
            _paymentStrategy.Pay(amount);
        }
    }
}
class Program
{
    static void Main(string[] args)
    {
        ShoppingCart shoppingCart = new ShoppingCart();
        shoppingCart.SetPaymentStrategy(new CreditCardPayment());
        shoppingCart.Checkout(100);
        
        shoppingCart.SetPaymentStrategy(new PaypalPayment());
        shoppingCart.Checkout(200.80);
        
        shoppingCart.SetPaymentStrategy(new CashPayment());
        shoppingCart.Checkout(300.50);
        
        ShoppingCart shoppingCart2 = new ShoppingCart();
        //shoppingCart2.SetPaymentStrategy(new CreditCardPayment());
        shoppingCart2.Checkout(600);
    }
}