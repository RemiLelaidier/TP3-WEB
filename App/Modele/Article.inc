<?php

namespace App\Modele;

class Article {
	
	/**
	 * 
	 * @var Categorie
	 */
	private $categorie ; 
	
	/**
	 * 
	 * @var string
	 */
	private $titre;
	/**
	 * 
	 * @var string
	 */
	private $auteur;
	/**
	 *
	 * @var string
	 */
	private $texte;
	
	/**
	 * constructeur
	 * @param string $titre
	 * @param string $auteur
	 * @param string $texte
	 */
	public function __construct($titre, $auteur, $texte) {
		$this->auteur =$auteur;
		$this->texte = $texte;
		$this->titre = $titre;
	}

	/**
	 * retourne la catégorie, si elle existe, de l'article
	 * @return Categorie
	 */
	public function getCategorie()
	{
		return $this->categorie;
	}
	
	/**
	 * pour affecter ou changer de catégorie
	 * @param Categorie $cat
	 */
	public function setCategorie(Categorie $cat)
	{
		$this->categorie = $cat;
	}

	/**
	 * retourne le titre de l'article
	 * @return string
	 */
	public function getTitre()
	{
		return $this->titre;
	}
	
	/**
	 * pour affecter ou changer de titre
	 * @param string $titre
	 */
	public function setTitre($titre)
	{
		$this->titre = titre;
	}

    /**
     * @return string
     */
	public function getAuteur(){
	    return $this->auteur;
    }

    /**
     * @param $auteur
     */
    public function setAuteur($auteur){
        $this->auteur = $auteur;
    }

    /**
     * @return string
     */
    public function getTexte(){
        return $this->texte;
    }

    /**
     * @param $texte
     */
    public function setTexte($texte){
        $this->texte = $texte;
    }
	
	/**
	 * pour obtenir une vue html de l'article
	 */
	public function getHtml()
	{
		$result = <<<EOR
		<fieldset>
			<legend>{$this->titre} par {$this->auteur}</legend>
			{$this->texte}
		</fieldset>
EOR;
		return $result;
	}
}
?>