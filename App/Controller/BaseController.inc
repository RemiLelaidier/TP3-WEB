<?php
/**
 * Created by PhpStorm.
 * User: leetspeakv2
 * Date: 22/11/16
 * Time: 13:20
 */

namespace App\Controller;


use App\Modele\Article;
use App\Modele\Categorie;

class BaseController extends Controller
{
    /**
     * Index
     */
    public function index(){
        self::checkPersistance();
        $categories = self::$persistanceProvider->getCategories();
        $this->render("index", compact('categories'));
    }

    /**
     * Articles
     */
    public function addArticle(){
        self::checkPersistance();
        if(!empty($_POST['titre']) && !empty($_POST['auteur']) && !empty($_POST['texte']) && !empty($_POST['categorie'])){
            $a = new Article($_POST['titre'], $_POST['auteur'], $_POST['texte']);
            $a->setCategorie(new Categorie($_POST['categorie']));
            if(self::$persistanceProvider->addArtcicle($a)){
                $message = "Article ajoute";
            }
            else{
                $message = "Echec de l'ajout";
            }
        }
        else{
            $message = "Les champs sont a remplir";
        }
        $categories = self::$persistanceProvider->getCategories();
        $this->render("create", compact('message','categories'));
    }

    /**
     * Categories
     */
}