/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package jdbcdemo;

import java.sql.*;

/**
 *
 * @author sn
 */
public class JDBCdemo {

    /**
     * @param args the command line arguments
     */
    
    static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";
    static final String DB_URL = "jdbc:mysql://localhost/STATEDB";
    
    static final String USER = "root";
    static final String PASS = "sn2606";
    
    public static void main(String[] args) {
        // TODO code application logic here
        
        Connection conn = null;
        Statement stmt = null;
        String sql;
        ResultSet rs;
        
        try {
            Class.forName("com.mysql.jdbc.Driver");

            System.out.println("Connecting to database...");
            conn = DriverManager.getConnection(DB_URL, USER, PASS);

            System.out.println("CREATE");
            stmt = conn.createStatement();
            sql = "INSERT INTO state VALUES('Assam', 'Dispu')";
            stmt.executeUpdate(sql);
            System.out.println("Record Inserted");
            
            System.out.println("RETRIEVE");
            stmt = conn.createStatement();
            sql = "SELECT * FROM state WHERE statename = 'Assam'";
            rs = stmt.executeQuery(sql);
            while (rs.next()) {
                System.out.println("State Name: " + rs.getString("statename"));
                System.out.println("State Capital: " + rs.getString("statecapital"));
            }
            
            System.out.println("UPDATE");
            stmt = conn.createStatement();
            sql = "UPDATE state SET statecapital='Dispur' WHERE statename='Assam'";
            stmt.executeUpdate(sql);
            
            stmt = conn.createStatement();
            sql = "SELECT * FROM state WHERE statename = 'Assam'";
            rs = stmt.executeQuery(sql);
            while (rs.next()) {
                System.out.println("State Name: " + rs.getString("statename"));
                System.out.println("State Capital: " + rs.getString("statecapital"));
            }
            
            System.out.println("Updated Successfully!");
            
            System.out.println("DELETE");
            stmt = conn.createStatement();
            sql = "DELETE FROM state WHERE statename = 'Kerala'";
            stmt.executeUpdate(sql);
            System.out.println("Deleted a row");
            
            rs.close();
            
        }catch(SQLException se){
            //Handle errors for JDBC
            se.printStackTrace();
        }catch(Exception e){
            //Handle errors for Class.forName
            e.printStackTrace();
        }finally{
            //finally block used to close resources
            try{
               if(stmt!=null)
                  conn.close();
            }catch(SQLException se){
            }// do nothing
            try{
               if(conn!=null)
                  conn.close();
            }catch(SQLException se){
               se.printStackTrace();
            }//end finally try
        }//end try     
        
    }
    
}
