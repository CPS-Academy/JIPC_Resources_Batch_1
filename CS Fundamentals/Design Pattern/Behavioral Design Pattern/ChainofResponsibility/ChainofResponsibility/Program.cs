abstract class Handler
{
    protected Handler nextHandler;

    public Handler SetNext(Handler handler)
    {
        nextHandler = handler;
        return handler;
    }

    public abstract void HandleRequest(string request);

}

class LowHandler : Handler
{
    public override void HandleRequest(string request)
    {
        if (request == "low")
        {
            Console.WriteLine("LowHandler Handle it");
        }
        else
        {
            nextHandler.HandleRequest(request);
        }
    }
}
class MidHandler : Handler
{
    public override void HandleRequest(string request)
    {
        if (request == "mid")
        {
            Console.WriteLine("MidHandler Handle it");
        }
        else
        {
            nextHandler.HandleRequest(request);
        }
    }
}
class HighHandler : Handler
{
    public override void HandleRequest(string request)
    {
        if (request == "high")
        {
            Console.WriteLine("HighHandler Handle it");
        }
        else
        {
            nextHandler.HandleRequest(request);
        }
    }
}
class Program
{
    static void Main(string[] args)
    {
        LowHandler low = new LowHandler();
        MidHandler mid = new MidHandler();
        HighHandler high = new HighHandler();

        low.SetNext(high).SetNext(mid);
        
        //low.HandleRequest("low");
        //low.HandleRequest("high");
        low.HandleRequest("mid");
    }
}