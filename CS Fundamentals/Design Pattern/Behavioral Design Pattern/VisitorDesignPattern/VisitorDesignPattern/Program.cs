interface IShape
{
    void Accept(IVisitor visitor);
}

interface IVisitor
{
    void VisitCircle(Circle circle);
    void VisitRectangle(Rectangle rectangle);
    
    //void VisitTriangle(Triangle trinagle)
}
// Element
class Circle : IShape
{
    public double Radius { get; set; }

    public Circle(double radius)
    {
        Radius = radius;
    }

    public void Accept(IVisitor visitor)
    {
        visitor.VisitCircle(this);
    }
}
//Element
class Rectangle : IShape
{
    public double Width { get; set; }
    public double Height { get; set; }

    public Rectangle(double width, double height)
    {
        Height = height;
        Width = width;
    }

    public void Accept(IVisitor visitor)
    {
        visitor.VisitRectangle(this);
    }
}

class AreaCalculatorVisitor : IVisitor
{
    public void VisitCircle(Circle circle)
    {
        double area = Math.PI *circle.Radius*circle.Radius;
        Console.WriteLine("Circle Area: {0}", area);
    }

    public void VisitRectangle(Rectangle rectangle)
    {
        double area = rectangle.Width * rectangle.Height;
        Console.WriteLine("Rectanlge Area: {0}", area);
    }
}
class Program
{
    static void Main(string[] args)
    {
        // List<IShape> shapes = new List<IShape>();
        // shapes.Add(new Circle(2));
        // shapes.Add(new Rectangle(2, 2));
        List<IShape> shapes = new List<IShape>
        {
            new Circle(2),
            new Rectangle(3, 2),
            new Rectangle(3, 4),
        };
        
        IVisitor visitor = new AreaCalculatorVisitor();

        foreach (var shape in shapes)
        {
            shape.Accept(visitor);
        }

    }
}