using System;
using System.Collections.Generic;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text.Json;
using System.Xml.Serialization;

namespace ConsoleApp1
{
    public class Person
    {
        public string Name { get; set; }
        public int Age { get; set; }
        int _idenNumber;
        //[NonSerialized]
        const string Planet = "Earth";
        public Person() { }
        public Person(int number)
        {
            _idenNumber = number;
        }
        public override string ToString()
        {
            return $"Name : {Name}, Age{Age}, Identification number {_idenNumber} " +
                $", Planet {Planet} ";
        }
    }
    class Shop
    {
        string filename = "Persons.json";
        string jsonString;
        //List<Person> newpersons;
        List<Person> persons;
        public Shop()
        {
            persons= new List<Person>()
            {
                new Person(123654) { Name = "Olena", Age = 21 },
                new Person(987456) { Name = "Mukola", Age = 22 },
                new Person(258963) { Name = "Oksana", Age = 23 }
            };
        }
        public void Save()
        {
           
            jsonString = JsonSerializer.Serialize(persons);
            File.WriteAllText(filename, jsonString);           

        }
        public void Load()
        {
            jsonString = File.ReadAllText(filename);
            persons = JsonSerializer.Deserialize<List<Person>>(jsonString);
           
        }
        public void Print()
        {
            foreach (var item in persons)
            {
                Console.WriteLine(item);
            }
        }

    }
    internal class Program
    {
        static void Main(string[] args)
        {
            
            try
            {
                Shop shop = new Shop();
                shop.Save();
                shop.Load();
                shop.Print();

              
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);

            }




            // XmlSerializer serializer = new XmlSerializer(typeof(List<Person>));
            //  XmlSerializer xmlFormat = new XmlSerializer(typeof(List<Person>));
            //try
            //{
            //    using (Stream fstream = File.Create("test.xml"))
            //    {
            //        serializer.Serialize(fstream, persons);
            //    }//Dispose()
            //    Console.WriteLine("Xml Serialize OK!!!!");
            //    List<Person> newpersons = null;
            //    // Person p = null;
            //    using (Stream fstream = File.OpenRead("test.xml"))
            //    {
            //        //p = (Person)binaryFormatter.Deserialize(fstream);
            //        newpersons = (List<Person>)serializer.Deserialize(fstream);
            //    }
            //    //Console.WriteLine(p);
            //    foreach (var item in newpersons)
            //    {
            //        Console.WriteLine(item);
            //    }

            //}
            //catch (Exception ex)
            //{
            //    Console.WriteLine(ex.Message);

            //}
        }
    }
}
