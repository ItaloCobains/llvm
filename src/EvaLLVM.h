/**
 * Eva to LLVR IR compiler
*/
#ifndef EvaLLVM_h
#define EvaLLVM_h

#include <string>
#include "llvm-10/llvm/IR/IRBuilder.h"
#include "llvm-10/llvm/IR/LLVMContext.h"
#include "llvm-10/llvm/IR/Module.h"

class EvaLLVM {
    public: 
        EvaLLVM() { moduleInit(); }

    /**
     * Execulta o programa
    */
   void exec(const std::string& program){
    // 1 parsing do programa
    // auto ast = parser->parser(program);

    // Compile LLVM IR

    module->print(llvm::outs(), nullptr);

    // Save module IR to file
    saveModuleToFile("./out.ll");
   }

   private:
    void saveModuleToFile(const std::string& fileName) {
        std::error_code errorCode;
        llvm::raw_fd_ostream outLL(fileName, errorCode);
        module->print(outLL, nullptr);
    }
    void moduleInit() {
        ctx = std::make_unique<llvm::LLVMContext>();
        module = std::make_unique<llvm::Module>("EvaLLVM", *ctx);
        builder = std::make_unique<llvm::IRBuilder<>>(*ctx);
    }

    std::unique_ptr<llvm::LLVMContext> ctx;
    std::unique_ptr<llvm::Module> module;
    std::unique_ptr<llvm::IRBuilder<>> builder;
};

#endif // EvaLLVM_h