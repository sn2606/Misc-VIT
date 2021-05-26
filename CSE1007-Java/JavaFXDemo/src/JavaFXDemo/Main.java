/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package JavaFXDemo;

import java.util.HashMap;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
//import javafx.scene.control.Button;
//import javafx.scene.control.Label;
//import javafx.scene.control.Menu;
//import javafx.scene.control.MenuBar;
//import javafx.scene.control.MenuItem;
import javafx.scene.control.TextField;
//import javafx.scene.layout.FlowPane;
//import javafx.scene.layout.StackPane;
import javafx.scene.layout.TilePane;
//import javafx.scene.layout.VBox;
import javafx.stage.Stage;
/**
 *
 * @author sn
 */
public class Main extends Application {
    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Assessment 3 Q2 by 19BCE0977");
        TextField b = new TextField();
        TextField c = new TextField();
//        StackPane stk = new StackPane();        
        TilePane tile = new TilePane();

//        stk.setMaxWidth(300);

        HashMap <String, String> courses = new HashMap<String, String>();
        courses.put("CSE1003", "Digital Logic and Design");
        courses.put("CSE1004", "Network and Communication");
        courses.put("CSE1007", "Java Programming");
        courses.put("MAT2001", "Statistics for Engineers");
        courses.put("MAT2002", "Application of Differential Calculus");
        courses.put("CSE2003", "Data Structures and Algorithms");
        courses.put("CSE2004", "Database Management System");
        courses.put("CSE2005", "Operating Systems");
        courses.put("CSE3001", "Software Engineering");
        courses.put("CSE3002", "Internet and Web Programming");
                
        EventHandler <ActionEvent> event = new EventHandler <ActionEvent>(){            
            @Override
            public void handle(ActionEvent e) {
                if(courses.containsKey(b.getText())){
                    System.out.println(courses.get(b.getText()));
                    c.setText(courses.get(b.getText()));
                } else {
                    c.setText("This course is not available!");
                }
            }
        };
        
        b.setOnAction(event);
        
        tile.getChildren().add(b);
        tile.getChildren().add(c);
        
        Scene sc = new Scene(tile, 500, 500);
        primaryStage.setScene(sc);
        primaryStage.show();
        
    }
    public static void main(String[] args) {
        launch(args);
    }
}