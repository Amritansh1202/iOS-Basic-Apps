//
//  ViewController.swift
//  Quizzler-iOS13
//
//  Created by Angela Yu on 12/07/2019.
//  Copyright © 2019 The App Brewery. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    @IBOutlet weak var scoreLabel: UILabel!
    @IBOutlet weak var questionLabel: UILabel!
    @IBOutlet weak var progressBar: UIProgressView!
    
    @IBOutlet weak var optionOne: UIButton!
    @IBOutlet weak var optionTwo: UIButton!
    @IBOutlet weak var optionThree: UIButton!
    
    var quizBrain = QuizBrain() 

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        updateUI()
    }
    
    @IBAction func answerButtonPressed(_ sender: UIButton) {
        
        let userAnswer = sender.currentTitle!
        let userGotItRight = quizBrain.checkAnswer(userAnswer)
        
        if userGotItRight {
            
            sender.backgroundColor = UIColor.green
        }
        else {
            sender.backgroundColor = UIColor.red
            var index = quizBrain.getCorrectAnswerNumber()
            if index == 0 {
                optionOne.backgroundColor = UIColor.green
            }
            else if index == 1 {
                optionTwo.backgroundColor = UIColor.green
            }
            else {
                optionThree.backgroundColor = UIColor.green
            }
        }
        
        quizBrain.nextQuestion()
        
        Timer.scheduledTimer(timeInterval: 0.2, target: self, selector: #selector(updateUI), userInfo: nil, repeats: false)
    }
    
    @objc func updateUI() {
        
        questionLabel.text = quizBrain.getQuestionText()
        
        optionOne.setTitle(quizBrain.getoptionOne(), for: .normal)
        optionTwo.setTitle(quizBrain.getoptionTwo(), for: .normal)
        optionThree.setTitle(quizBrain.getoptionThree(), for: .normal)
        
        optionOne.backgroundColor = UIColor.clear
        optionTwo.backgroundColor = UIColor.clear
        optionThree.backgroundColor = UIColor.clear
        
        progressBar.progress = quizBrain.getProgress()
        scoreLabel.text = "Score : \(quizBrain.getScore() )"
    }
}

