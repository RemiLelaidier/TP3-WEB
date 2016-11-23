<?php

namespace App\Donnees;

use \App\Modele\Categorie;
use \App\Modele\Article;

class XML implements Persistance {

    /**
     * @var string Chemin vers le fichier XML
     */
    private $ficXML;

    /**
     * @var SimpleXMLElement Le fichier XML
     */
    private $XML;

    /**
     * @var Categorie Liste des categories
     */
    private $categories;


    /*-------------------------------------------------*/
    /**
     * Constructeur qui lit le fichier XML
     */
    public function __construct(){
        $this->XML = simplexml_load_file('./news/news.xml');
    }

    /**
     * permet de charger toutes les catégories et tous les articles
     * @return boolean : vrai en cas de succès, faux sinon
     */
    public function charger(){
        // On explore les categorie
        $k = 0;
        foreach ($this->XML->categorie as $categorie){
            $this->categories[$k] = new Categorie($categorie->nom->__toString());

            // Et les articles de la categorie
            foreach ($categorie->article as $a){
                $newa = new Article($a->titre->__toString(), $a->auteur->__toString(), $a->texte->__toString());
                $this->categories[$k]->addArticle($newa);
            }
            $k++;
        }
    }

    /**
     * @return array retourne un tableau de toutes les catégories lues
     */
    public function getCategories(){
        if(count($this->categories) == 0)
            $this->charger();
        return $this->categories;
    }

    /**
     * @return array retourne un tableau de tous les articles lus de toutes les catégories lues
     */
    public function getArticles(){
        if(count($this->categories) == 0)
            $this->charger();
        $result = array();
        foreach ($this->categories as $categorie){
            foreach ($categorie->getArticles() as $article){
                array_push($result, $article);
            }
        }
        return $result;
    }

    /**
     * @param \App\Donnees\Article $article article a jouter
     * @return bool false si echec sinon true
     */
    public function addArticle($article){
        $done = false;
        foreach ($this->XML->categorie as $category){
            if($category == $article->getCategorie()){
                $a = $category->addChild('article');
                $a->addChild('titre', $article->getTitre());
                $a->addChild('auteur', $article->getAuteur());
                $a->addChild('texte', $article->getTexte());
                $this->XML->asXML("./news/news.xml");
                $done = true;
            }
        }
        return $done;
    }
}