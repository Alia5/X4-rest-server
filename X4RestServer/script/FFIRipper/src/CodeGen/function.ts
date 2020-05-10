import { Param } from './param';

export class CFunction {

    public name: string;
    public returnType: string;

    public args: Param[];

    public constructor(protected functionStr: string) {
        this.name = this.functionStr.split('(')[0].split(' ').splice(-1).join('');
        this.returnType = this.functionStr.split('(')[0].split(' ').slice(0,-1).join(' ');
        const strArgs = this.functionStr.replace(/\).*?;/g, '')
            .split('(').slice(1).join(' ').split(',').filter((s) => s !== 'void');
        this.args = strArgs.map((a) => new Param(a.trim()));
    }

    public toUsingString(): string {
        return `using ${this.name} = ${this.returnType} (*)(${this.args.join(', ')});`;
    }

    public toString(): string {
        return this.functionStr;
    }

}
