using System;
using System.Collections.Generic;

// Onion Architecture

/*
Student:
StudentId, Name, Email
1, shahriar, shahriar@gmail.com
2, shahriar2, shahriar2@gmail.com

Trainer:
TrainerId, Name, Email

Course:
CourseId, Name, Description

Enrollment:
*/


// Fake Database
public class Database {
    public IList<Student> students;
    public IList<Course> courses;
    public IList<Trainer> trainers;

    public Database() {
        students = new List<Student>();
        courses = new List<Course>();
        trainers = new List<Trainer>();
    }
}

// Core Layer

// Models
public class Student {
    public int StudentId { get; set; }
    public string Name { get; set; }
    public string Email { get; set; }
}

public class Trainer {
    public int TrainerId { get; set; }
    public string Name { get; set; }
    public string Email { get; set; }
}

public class Course {
    public int CourseId { get; set; }
    public string Name { get; set; }
    public string Description { get; set; }
}

// Interfaces

// Repositories
public interface IStudentRepository {
    void AddStudent (Student student);
    void RemoveStudent (Student student);
    Student UpdateStudent (Student student);
    IList<Student> GetAllStudents();
}

public interface ITrainerRepository {
    void Add (Trainer trainer); 
    void Remove (Trainer trainer);
    Trainer Update (Trainer trainer);
}

public interface ICourseRepository {
    void Add (Course course);
    void Remove (Course course);
    Course Update (Course course);
}

// Services
public interface IStudentService {
    void AddStudent(Student student);
    void RemoveStudent(Student student);
    Student UpdateStudent(Student student);
    IList<Student> GetAllStudents();
}

public interface ITrainerService {
    void Add(Trainer trainer);
    void Remove(Trainer trainer);
    Trainer Update(Trainer trainer);
}

public interface ICourseService {
    void Add(Course course);
    void Remove(Course course);
    Course Update(Course course);
}

// Infrastructure Layer - Data Access Layer - Data layer
// Repositories
public class StudentRepository : IStudentRepository {
    Database _db;

    public StudentRepository (Database db) {
        _db = db;
    }

    public void AddStudent (Student student) {
        Console.WriteLine("StudentRepository.AddStudent()");
        _db.students.Add(student);
    }

    public void RemoveStudent (Student student) {
        _db.students.Remove(student);
    }

    public Student UpdateStudent (Student student) {
        // Update logic here
        return student;
    }

    public IList<Student> GetAllStudents() {
        return _db.students;
    }
}

public class TrainerRepository : ITrainerRepository {
    Database _db;

    public TrainerRepository(Database db) {
        _db = db;
    }

    public void Add (Trainer trainer) {
        _db.trainers.Add(trainer);
    }

    public void Remove (Trainer trainer) {
        _db.trainers.Remove(trainer);
    }

    public Trainer Update (Trainer trainer) {
        // Update logic here
        return trainer;
    }
}

public class CourseRepository : ICourseRepository {
    Database _db;

    public CourseRepository(Database db) {
        _db = db;
    }

    public void Add (Course course) {
        _db.courses.Add(course);
    }

    public void Remove (Course course) {
        _db.courses.Remove(course);
    }

    public Course Update (Course course) {
        // Update logic here
        return course;
    }
}

// Service Layer - Business Logic Layer
// Services - Business Logic

public class StudentService : IStudentService {
    IStudentRepository _studentRepository;

    public StudentService (IStudentRepository studentRepository) {
        _studentRepository = studentRepository;
    }

    public void AddStudent(Student student) {
        // Business Logic
        Console.WriteLine("StudentService.AddStudent()");
        _studentRepository.AddStudent(student);
    }

    public void RemoveStudent(Student student) {
        // Business Logic
        _studentRepository.RemoveStudent(student);
    }

    public Student UpdateStudent(Student student) {
        // Business Logic
        return _studentRepository.UpdateStudent(student);
    }

    public IList<Student> GetAllStudents() {
        return _studentRepository.GetAllStudents();
    }
}

public class TrainerService : ITrainerService {
    ITrainerRepository _trainerRepository;

    public TrainerService(ITrainerRepository trainerRepository) {
        _trainerRepository = trainerRepository;
    }

    public void Add(Trainer trainer) {
        // Business Logic
        _trainerRepository.Add(trainer);
    }

    public void Remove(Trainer trainer) {
        // Business Logic
        _trainerRepository.Remove(trainer);
    }

    public Trainer Update(Trainer trainer) {
        // Business Logic
        return _trainerRepository.Update(trainer);
    }
}

public class CourseService : ICourseService {
    ICourseRepository _courseRepository; 

    public CourseService(ICourseRepository courseRepository) {
        _courseRepository = courseRepository;
    }

    public void Add(Course course) {
        // Business Logic
        _courseRepository.Add(course);
    }

    public void Remove(Course course) {
        // Business Logic
        _courseRepository.Remove(course);
    }

    public Course Update(Course course) {
        // Business Logic
        return _courseRepository.Update(course);
    }
}

// Presentation Layer - UI Layer - Frontend Layer
// Controllers

public class StudentController {
    IStudentService _studentService;

    public StudentController(IStudentService studentService) {
        _studentService = studentService;
    }

    public void AddStudent(Student student) {
        Console.WriteLine("StudentController.AddStudent()");
        _studentService.AddStudent(student);
    }

    public void RemoveStudent(Student student) {
        _studentService.RemoveStudent(student);
    }

    public Student UpdateStudent(Student student) {
        return _studentService.UpdateStudent(student);
    }

    public IList<Student> GetAllStudents() {
        return _studentService.GetAllStudents();
    }
}

public class TrainerController {
    ITrainerService _trainerService;

    public TrainerController(ITrainerService trainerService) {
        _trainerService = trainerService;
    }

    public void Add(Trainer trainer) {
        _trainerService.Add(trainer);
    }

    public void Remove(Trainer trainer) {
        _trainerService.Remove(trainer);
    }

    public Trainer Update(Trainer trainer) {
        return _trainerService.Update(trainer);
    }
}

public class CourseController {
    ICourseService _courseService;

    public CourseController(ICourseService courseService) {
        _courseService = courseService;
    }

    public void Add(Course course) {
        _courseService.Add(course);
    }

    public void Remove(Course course) {
        _courseService.Remove(course);
    }

    public Course Update(Course course) {
        return _courseService.Update(course);
    }
}

// Core Layer -> Models, Interfaces
// Infrastructure Layer -> Repositories
// Service Layer -> Services
// Presentation Layer -> Controllers

// Frontend -> HTML -> JS -> Controllers -> Services -> Controller(Backend)(API) -> Services -> Repositories -> Database

class Program {
    public static void Main () {
        Database db = new Database();
        IStudentRepository studentRepository = new StudentRepository(db);
        IStudentService studentService = new StudentService(studentRepository);
        StudentController studentController = new StudentController(studentService);

        Student student = new Student {
            StudentId = 1,
            Name = "Shahriar",
            Email = "shahriar@gmail.com"
        };

        Student student2 = new Student {
            StudentId = 2,
            Name = "Shahriar2",
            Email = "shahriar2@gmail.com"
        };

        studentController.AddStudent(student);
        studentController.AddStudent(student2);
        Console.WriteLine("------------------------------");
        Console.WriteLine("Student Added");
        Console.WriteLine("------------------------------");
        
        IList<Student> students = studentController.GetAllStudents();
        foreach (var s in students) {
            Console.WriteLine("Student Details:");
            Console.WriteLine(s.Name);
            Console.WriteLine(s.Email);
            Console.WriteLine(s.StudentId);
            Console.WriteLine("------------------------------");
        }
    }
}


