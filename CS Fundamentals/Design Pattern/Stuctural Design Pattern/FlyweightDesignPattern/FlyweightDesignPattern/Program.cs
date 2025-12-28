public interface ICircleStyle
{
    void Draw(int x, int y, int radius);
}

public class SharedCircleStyle: ICircleStyle
{

    private string _color;
    private string _lineStyle;
    public SharedCircleStyle(string color, string lineStyle)
    {
        _color = color;
        _lineStyle = lineStyle;
        Console.WriteLine($"-> Created New Shared Circle Style: {_color} {_lineStyle}");
    }
    public void Draw(int x, int y, int radius)
    {
        
        //throw new NotImplementedException();
    }

    public string GetStateKey()
    {
        return $"{_color}-{_lineStyle}";
    }
}

public class StyleFactory
{
    private Dictionary<string, ICircleStyle> _circleStyles = new Dictionary<string, ICircleStyle>();

    public ICircleStyle GetStyle(string color, string lineStyle)
    {
        string key = $"{color}-{lineStyle}";
        if (!_circleStyles.ContainsKey(key))
        {
            _circleStyles.Add(key, new SharedCircleStyle(color, lineStyle));
        }
        return _circleStyles[key];
    }
}

public class DrawingCanvas
{
    private class CircleInstance
    {
        public int X, Y;
        public int Radious;
        public ICircleStyle circleStyle;
    }
    private StyleFactory _styleFactory = new StyleFactory();
    private List<CircleInstance> _circles = new List<CircleInstance>();
    public void AddCircle(int x, int y, int radious, string color, string lineStyle)
    {
        ICircleStyle circle = _styleFactory.GetStyle(color, lineStyle);

        _circles.Add(new CircleInstance
        {
            X = x,
            Y = y,
            Radious = radious,
            circleStyle = circle
        });
    }

    public void Render()
    {
        Console.WriteLine("Rendering Canvas");
    }

}


public class Program
{
    public static void Main()
    {
        DrawingCanvas drawingCanvas = new DrawingCanvas();
        drawingCanvas.AddCircle(0, 0, 0, "red", "red");
        drawingCanvas.AddCircle(0, 0, 0, "green", "green");
        drawingCanvas.AddCircle(0, 0, 0, "blue", "blue");
        drawingCanvas.AddCircle(0, 0, 0, "green", "green");
    }
}