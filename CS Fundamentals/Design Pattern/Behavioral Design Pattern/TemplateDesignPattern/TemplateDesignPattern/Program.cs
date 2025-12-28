abstract class ReportGenerator
{
    public void GenerateReport()
    {
        FetchData();
        FormatData();
        ExportReport();
        NotifyUser();
    }
    protected virtual void FetchData(){
        Console.WriteLine("Fetching data...");
    }

    protected abstract void FormatData();
    protected abstract void ExportReport();

    protected virtual void NotifyUser()
    {
        Console.WriteLine("Notifying user");
    }
}

class PdfReportGenerator : ReportGenerator
{
    protected override void FormatData()
    {
        Console.WriteLine("Formating data for PDF report");
    }

    protected override void ExportReport()
    {
        Console.WriteLine("Exporting data for PDF report");
    }
}
class ExcelReportGenerator : ReportGenerator
{
    protected override void FormatData()
    {
        Console.WriteLine("Formating data for Excel report");
    }

    protected override void ExportReport()
    {
        Console.WriteLine("Exporting data for Excel report");
    }
}
class Program
{
    static void Main(string[] args)
    {
        ReportGenerator pdf = new PdfReportGenerator();
        pdf.GenerateReport();
        
        ReportGenerator excel = new ExcelReportGenerator();
        excel.GenerateReport();
        
    }
}