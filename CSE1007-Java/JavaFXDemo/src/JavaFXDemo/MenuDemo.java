/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package JavaFXDemo;

import javafx.application.Application;
//import java.util.HashMap;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
//import javafx.scene.control.MenuBar;
//import javafx.scene.control.MenuItem;
//import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
//import javafx.scene.control.TextField;
//import javafx.scene.layout.FlowPane;
//import javafx.scene.layout.StackPane;
//import javafx.scene.layout.TilePane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

/**
 *
 * @author sn
 */
public class MenuDemo extends Application {    
    @Override
    public void start(Stage PrimaryStage) {
    
        PrimaryStage.setTitle("Menu Demo");
        
        Menu m = new Menu("SchoolName");
        
        MenuItem m1 = new MenuItem("SCOPE");
        MenuItem m2 = new MenuItem("SITE");
        MenuItem m3 = new MenuItem("SELECT");
        MenuItem m4 = new MenuItem("SENSE");
        m.getItems().add(m1);
        m.getItems().add(m2);
        m.getItems().add(m3);
        m.getItems().add(m4);
                
        MenuBar mb = new MenuBar();
        mb.getMenus().add(m);
        
        Label lb = new Label("No menu item selected");
        EventHandler<ActionEvent> event = (ActionEvent e) -> {
            lb.setText(((MenuItem)e.getSource()).getText() + " selected");
        };        
        
        m1.setOnAction(event);
        m2.setOnAction(event);
        m3.setOnAction(event);
        m4.setOnAction(event);
        
        VBox vb = new VBox(mb, lb);
        
        Scene s = new Scene(vb, 500, 300);
        PrimaryStage.setScene(s);
        PrimaryStage.show();
    }
    
    public static void main(String[] args) {
        launch(args);
    }
}
