using System;
using System.Collections.Generic;

// Deep Copy 
// Shallow Copy

public class Product {
    public string Id { get; set; }
    public string Name { get; set; }
    public decimal Price { get; set; }
    public string Category { get; set; }
    public string Description { get; set; }
    public string ImageUrl { get; set; }
    public bool IsAvailable { get; set; }
    public int Stock { get; set; }
    public string CreatedBy { get; set; }
    public string UpdatedBy { get; set; }
    public IList<string> Tags { get; set; }

    public Product Clone() {
        Product copy = (Product) this.MemberwiseClone();
        copy.Tags = new List<string>(this.Tags);
        return copy;
    }
}

public class Category {
    public string Id { get; set; }
    public string Name { get; set; }
}

public interface IProductService {
    IList<Product> CopyProducts(IList<Product> products);
    void ShowProduct(Product product);
}

public class ProductService : IProductService {
    public IList<Product> CopyProducts(IList<Product> products) {
        IList<Product> productsCopy = new List<Product>();
        
        foreach (Product product in products) {
            Product productCopy = product.Clone();
            productCopy.Id = Guid.NewGuid().ToString();
            productsCopy.Add(productCopy);
        }

        return productsCopy;
    }

    public void ShowProduct(Product product) {
        Console.WriteLine("Product Id: " + product.Id);
        Console.WriteLine("Product Name: " + product.Name);
        Console.WriteLine("Product Price: " + product.Price);
        Console.WriteLine("Product Category: " + product.Category);
        Console.WriteLine("Product Description: " + product.Description);

        foreach (string tag in product.Tags) {
            Console.WriteLine("Product Tag: " + tag);
        }
    }
}

class Program
{
    public static void Main()
    {
        IList<Product> products = new List<Product>() {
            new Product() { 
                Id = "ksd", 
                Name = "Product 1", 
                Price = 100, 
                Category = "Category 1", 
                Description = "Description 1", 
                ImageUrl = "http://localhost:5000/images/product1.jpg",
                Tags = new List<string>() {
                    "Tag 1",
                    "Tag 2",
                    "Tag 3"
                }
                },
            new Product() { 
                Id = "ksd", 
                Name = "Product 2", 
                Price = 200, 
                Category = "Category 2", 
                Description = "Description 2", 
                ImageUrl = "http://localhost:5000/images/product2.jpg",
                Tags = new List<string>() {
                    "Tag 1",
                    "Tag 2",
                    "Tag 3"
                }
                },
            new Product() { 
                Id = "ksd",
                Name = "Product 3", 
                Price = 300, 
                Category = "Category 3", 
                Description = "Description 3", 
                ImageUrl = "http://localhost:5000/images/product3.jpg",
                Tags = new List<string>() {
                    "Tag 1",
                    "Tag 2",
                    "Tag 3"
                }
                }
            };

        IProductService productService = new ProductService();
        IList<Product> productsCopy = productService.CopyProducts(products);

        Console.WriteLine("Original Products:");
        foreach(Product product in products) {
            productService.ShowProduct(product);
            Console.WriteLine("");
        }

        Console.WriteLine("");
        Console.WriteLine("Copied Products:");
        
        foreach(Product product in productsCopy) {
            productService.ShowProduct(product);
            Console.WriteLine("");
        }

        productsCopy[0].Tags[0] = "Changed Tag 1";
        Console.WriteLine("After changing tag 1 in productsCopy");

        Console.WriteLine("Product: {0}", products[0].Tags[0]);
        Console.WriteLine("Product Copy: {0}", productsCopy[0].Tags[0]);
        
    }
}
