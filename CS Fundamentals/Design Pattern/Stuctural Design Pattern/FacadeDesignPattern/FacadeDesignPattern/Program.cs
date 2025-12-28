// Trip Complete
// - BookFlight() - flight 
// - BookHotel() - hotel 
// - BookTaxi() - taxi 


public class FlightBooking
{
    public void BookFlight()
    {
        Console.WriteLine("Booking flight");
    }
}
public class HotelBooking
{
    public void BookHotel()
    {
       Console.WriteLine("Booking hotel");
    }
}
public class TaxiBooking
{
    public void BookTaxi()
    {
        Console.WriteLine("Booking taxi");
    }
}


public class TravelFacade
{
    private FlightBooking _flightBooking;
    private HotelBooking _hotelBooking;
    private TaxiBooking _taxiBooking;

    public TravelFacade()
    {
        _flightBooking = new FlightBooking();
        _hotelBooking = new HotelBooking();
        _taxiBooking = new TaxiBooking();
    }

    public void BookFlightComplete()
    {
        _flightBooking.BookFlight();
        _hotelBooking.BookHotel();
        _taxiBooking.BookTaxi();
        Console.WriteLine("Booking flight complete");
    }
}

class Program
{
    static void Main(string[] args)
    {
        var travelFacade = new TravelFacade();
        travelFacade.BookFlightComplete();
    }
}
