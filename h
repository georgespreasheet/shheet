// Définir les heures cibles
var heuresCibles = [12, 13, 14, 15];

function compteAReboursPourHeure() {
  var maintenant = new Date();
  
  // Trouver l'heure cible suivante
  var heureCible = null;
  for (var i = 0; i < heuresCibles.length; i++) {
    if (heuresCibles[i] > maintenant.getHours()) {
      heureCible = heuresCibles[i];
      break;
    }
  }
  
  // Si aucune heure cible n'est trouvée, prendre la première heure de la liste pour le lendemain
  if (heureCible === null) {
    heureCible = heuresCibles[0] + 24;
  }
  
  // Créer une nouvelle date pour l'heure cible
  var dateCible = new Date();
  dateCible.setHours(heureCible);
  dateCible.setMinutes(0);
  dateCible.setSeconds(0);
  dateCible.setMilliseconds(0);
  
  // Calculer le temps restant jusqu'à l'heure cible
  var tempsRestant = obtenirTempsRestant(dateCible);
  
  // Afficher le temps restant
  Logger.log(tempsRestant.heures + "h " + tempsRestant.minutes + "m " + tempsRestant.secondes + "s ");
}

function obtenirTempsRestant(dateCible) {
  var maintenant = new Date();
  var tempsRestant = dateCible - maintenant;  // En millisecondes

  var secondes = Math.floor((tempsRestant / 1000) % 60);
  var minutes = Math.floor((tempsRestant / (1000 * 60)) % 60);
  var heures = Math.floor((tempsRestant / (1000 * 60 * 60)) % 24);
  
  return {
    'heures': heures,
    'minutes': minutes,
    'secondes': secondes
  };
}
