

public interface IColor
{
    string Fill();
}

public class Red : IColor
{
    public string Fill() => "Red";
}
public class Green : IColor
{
    public string Fill() => "Green";
}
public class Blue : IColor
{
    public string Fill() => "Blue";
}

public abstract class Shape
{
    public IColor _color;

    public Shape(IColor color)
    {
        _color = color;
    }
    
    public abstract void Draw();
}

public class Circle : Shape
{
    public Circle(IColor color) : base(color) { }

    public override void Draw()
    {
        Console.WriteLine("Circle Draw "+_color.Fill());
    }
}

public class Square : Shape
{
    public Square(IColor color) : base(color) { }

    public override void Draw()
    {
        Console.WriteLine("Square Draw "+_color.Fill());
    }
}
public class Triangle : Shape
{
    public Triangle(IColor color) : base(color) { }

    public override void Draw()
    {
        Console.WriteLine("Triangle Draw "+ _color.Fill());
    }
}



class Program
{
    static void Main(string[] args)
    {
        Shape circleShape = new Circle(new Red());
        circleShape.Draw();
        Shape squareShape = new Square(new Green());
        squareShape.Draw();
        Shape triangleShape = new Triangle(new Green());
        triangleShape.Draw();
    }
}