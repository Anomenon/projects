public class Main {
    public static void main(String[] args) {
        new School();
    }
}

class School {
    private SchoolMember[] members;
    private SchoolClass[] classes;

    public School(){
        System.out.println("Created School");
    }

    public SchoolMember[] getMembers(){
        return this.members;
    }

    public void setMembers(SchoolMember[] members) {
        this.members = members;
    }

    public void addMember(SchoolMember member){

    }

    public void removeMember(SchoolMember member){

    }

    public SchoolClass[] getClasses(){
        return this.classes;
    }

    public void setClasses(SchoolClass[] classes) {
        this.classes = classes;
    }

    public void addClass(SchoolClass Class){

    }

    public void removeClass(SchoolClass Class){

    }
}

class SchoolMember {
    private int id;
    private String name;
    private String surname;
    protected int accessLevel;

    public SchoolMember(int id, String name, String surname, int accessLevel){
        System.out.println("Created School Member");
    }

    public int getId(){
        return this.id;
    }

    public String getName(){
        return this.name;
    }

    public String getSurname(){
        return this.surname;
    }
}

class SchoolClass {
    private int id;
    private String name;
    private Teacher teacher;
    private Student[] students;
    
    public SchoolClass(int id, String name){
        System.out.println("Created School Class");
    }

    public int getId() {
        return this.id;
    }

    public String getName() {
        return this.name;
    }
    
    public Teacher getTeacher() {
        return this.teacher;
    }
    
    public Student[] getStudents() {
        return this.students;
    }

    public void setStudents(Student[] students) {

    }
}

class Teacher extends SchoolMember{
    Teacher(int id, String name, String surname){
        super(id, name, surname, 0);
    }
}

class Student extends SchoolMember{
    Student(int id, String name, String surname){
        super(id, name, surname, 0);
    }
}