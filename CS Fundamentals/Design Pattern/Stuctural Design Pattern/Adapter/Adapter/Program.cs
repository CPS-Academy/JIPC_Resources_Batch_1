using System;
using System.Xml;
using System.Xml.Linq;

public interface IDataProcesser
{
    void ProcessData(string procesedData);
}

public class JsonDataProceser : IDataProcesser
{
    public void ProcessData(string jsonData)
    {
        Console.WriteLine("Processing JSON data");
        Console.WriteLine(jsonData);
    }
}

public class XmlDataProvider{
    public string GetXmlData()
    {
        XDocument xmlDocc = new XDocument(
            new XElement("User", 
                new XElement("Name", "Subhashis"),
                new XElement("Age", 19),
                new XElement("Country", "Bangladesh")
            )
            );
        return xmlDocc.ToString(); 
    }
}


public class XmlToJsonAdapter : IDataProcesser
{
    private readonly XmlDataProvider _xmlDataProvider;

    public XmlToJsonAdapter(XmlDataProvider xmlProvider)
    {
        _xmlDataProvider = xmlProvider;
    }
    public void ProcessData(string procesedData)
    {
        string xmlData = _xmlDataProvider.GetXmlData();
        
        XmlDocument doc = new XmlDocument();
        doc.LoadXml(xmlData);
        string convertedJson = Newtonsoft.Json.JsonConvert.SerializeXNode(doc, Newtonsoft.Json.Formatting.Indented, 
            true);

        Console.WriteLine(convertedJson);
    }
}

class Program
{
    static void Main(string[] args)
    {
        
    }
}